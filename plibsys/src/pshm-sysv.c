/*
 * Copyright (C) 2010-2016 Alexander Saprykin <xelfium@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "pmem.h"
#include "psemaphore.h"
#include "pshm.h"
#include "perror-private.h"
#include "pipc-private.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>

#define P_SHM_SUFFIX		"_p_shm_object"
#define P_SHM_INVALID_HDL	-1

typedef pint pshm_hdl;

struct PShm_ {
	pboolean	file_created;
	key_t		unix_key;
	pchar		*platform_key;
	pshm_hdl	shm_hdl;
	ppointer	addr;
	psize		size;
	PSemaphore	*sem;
	PShmAccessPerms	perms;
};

static pboolean pp_shm_create_handle (PShm *shm, PError **error);
static void pp_shm_clean_handle (PShm *shm);

static pboolean
pp_shm_create_handle (PShm	*shm,
		      PError	**error)
{
	pboolean	is_exists;
	pint		flags, built;
	struct shmid_ds	shm_stat;

	if (P_UNLIKELY (shm == NULL || shm->platform_key == NULL)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IPC_INVALID_ARGUMENT,
				     0,
				     "Invalid input argument");
		return FALSE;
	}

	is_exists = FALSE;

	if (P_UNLIKELY ((built = p_ipc_unix_create_key_file (shm->platform_key)) == -1)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_ipc (),
				     p_error_get_last_error (),
				     "Failed to create key file");
		pp_shm_clean_handle (shm);
		return FALSE;
	} else if (built == 0)
		shm->file_created = TRUE;

	if (P_UNLIKELY ((shm->unix_key = p_ipc_unix_get_ftok_key (shm->platform_key)) == -1)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_ipc (),
				     p_error_get_last_error (),
				     "Failed to get unique IPC key");
		pp_shm_clean_handle (shm);
		return FALSE;
	}

	flags = (shm->perms == P_SHM_ACCESS_READONLY) ? 0444 : 0660;

	if ((shm->shm_hdl = shmget (shm->unix_key,
				    shm->size,
				    IPC_CREAT | IPC_EXCL | flags)) == P_SHM_INVALID_HDL) {
		if (p_error_get_last_error () == EEXIST) {
			is_exists = TRUE;

			shm->shm_hdl = shmget (shm->unix_key, 0, flags);
		}
	} else
		shm->file_created = (built == 1);

	if (P_UNLIKELY (shm->shm_hdl == P_SHM_INVALID_HDL)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_ipc (),
				     p_error_get_last_error (),
				     "Failed to call shmget() to create memory segment");
		pp_shm_clean_handle (shm);
		return FALSE;
	}

	if (P_UNLIKELY (shmctl (shm->shm_hdl, IPC_STAT, &shm_stat) == -1)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_ipc (),
				     p_error_get_last_error (),
				     "Failed to call shmctl() to get memory segment size");
		pp_shm_clean_handle (shm);
		return FALSE;
	}

	shm->size = shm_stat.shm_segsz;

	flags = (shm->perms == P_SHM_ACCESS_READONLY) ? SHM_RDONLY : 0;

	if (P_UNLIKELY ((shm->addr = shmat (shm->shm_hdl, 0, flags)) == (void *) -1)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_ipc (),
				     p_error_get_last_error (),
				     "Failed to call shmat() to attach to the memory segment");
		pp_shm_clean_handle (shm);
		return FALSE;
	}

	if (P_UNLIKELY ((shm->sem = p_semaphore_new (shm->platform_key, 1,
						     is_exists ? P_SEM_ACCESS_OPEN : P_SEM_ACCESS_CREATE,
						     error)) == NULL)) {
		pp_shm_clean_handle (shm);
		return FALSE;
	}

	return TRUE;
}

static void
pp_shm_clean_handle (PShm *shm)
{
	struct shmid_ds shm_stat;

	if (P_LIKELY (shm->addr != NULL)) {
		if (P_UNLIKELY (shmdt (shm->addr) == -1))
			P_ERROR ("PShm: shmdt() failed");

		if (P_UNLIKELY (shmctl (shm->shm_hdl, IPC_STAT, &shm_stat) == -1))
			P_ERROR ("PShm: failed to call shmctl() with IPC_STAT");

		if (P_UNLIKELY (shm_stat.shm_nattch == 0 && shmctl (shm->shm_hdl, IPC_RMID, 0) == -1))
			P_ERROR ("PShm: failed to call shmctl() with IPC_RMID");
	}

	if (shm->file_created == TRUE && unlink (shm->platform_key) == -1)
		P_ERROR ("PShm: failed to remove key file with unlink()");

	if (P_LIKELY (shm->sem != NULL)) {
		p_semaphore_free (shm->sem);
		shm->sem = NULL;
	}

	shm->file_created = FALSE;
	shm->unix_key     = -1;
	shm->shm_hdl      = P_SHM_INVALID_HDL;
	shm->addr         = NULL;
	shm->size         = 0;
}

P_LIB_API PShm *
p_shm_new (const pchar		*name,
	   psize		size,
	   PShmAccessPerms	perms,
	   PError		**error)
{
	PShm	*ret;
	pchar	*new_name;

	if (P_UNLIKELY (name == NULL)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IPC_INVALID_ARGUMENT,
				     0,
				     "Invalid input argument");
		return NULL;
	}

	if (P_UNLIKELY ((ret = p_malloc0 (sizeof (PShm))) == NULL)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IPC_NO_RESOURCES,
				     0,
				     "Failed to allocate memory for shared segment");
		return NULL;
	}

	if (P_UNLIKELY ((new_name = p_malloc0 (strlen (name) + strlen (P_SHM_SUFFIX) + 1)) == NULL)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IPC_NO_RESOURCES,
				     0,
				     "Failed to allocate memory for segment name");
		p_shm_free (ret);
		return NULL;
	}

	strcpy (new_name, name);
	strcat (new_name, P_SHM_SUFFIX);

	ret->platform_key = p_ipc_get_platform_key (new_name, FALSE);
	ret->perms        = perms;
	ret->size         = size;

	p_free (new_name);

	if (P_UNLIKELY (pp_shm_create_handle (ret, error) == FALSE)) {
		p_shm_free (ret);
		return NULL;
	}

	if (P_LIKELY (ret->size > size && size != 0))
		ret->size = size;

	return ret;
}

P_LIB_API void
p_shm_take_ownership (PShm *shm)
{
	if (P_UNLIKELY (shm == NULL))
		return;

	shm->file_created = TRUE;
	p_semaphore_take_ownership (shm->sem);
}

P_LIB_API void
p_shm_free (PShm *shm)
{
	if (P_UNLIKELY (shm == NULL))
		return;

	pp_shm_clean_handle (shm);

	if (P_LIKELY (shm->platform_key != NULL))
		p_free (shm->platform_key);

	p_free (shm);
}

P_LIB_API pboolean
p_shm_lock (PShm	*shm,
	    PError	**error)
{
	if (P_UNLIKELY (shm == NULL)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IPC_INVALID_ARGUMENT,
				     0,
				     "Invalid input argument");
		return FALSE;
	}

	return p_semaphore_acquire (shm->sem, error);
}

P_LIB_API pboolean
p_shm_unlock (PShm	*shm,
	      PError	**error)
{
	if (P_UNLIKELY (shm == NULL)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IPC_INVALID_ARGUMENT,
				     0,
				     "Invalid input argument");
		return FALSE;
	}

	return p_semaphore_release (shm->sem, error);
}

P_LIB_API ppointer
p_shm_get_address (const PShm *shm)
{
	if (P_UNLIKELY (shm == NULL))
		return NULL;

	return shm->addr;
}

P_LIB_API psize
p_shm_get_size (const PShm *shm)
{
	if (P_UNLIKELY (shm == NULL))
		return 0;

	return shm->size;
}
