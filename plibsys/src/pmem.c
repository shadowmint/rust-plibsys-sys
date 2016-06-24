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

#include <string.h>
#include <stdlib.h>

#include "pmem.h"
#include "perror-private.h"
#include "psysclose-private.h"

#ifndef P_OS_WIN
#  include <unistd.h>
#  include <sys/types.h>
#  include <sys/mman.h>
#  include <sys/stat.h>
#  include <fcntl.h>
#endif

static pboolean		p_mem_table_inited = FALSE;
static PMemVTable	p_mem_table;

void
p_mem_init (void)
{
	if (P_UNLIKELY (p_mem_table_inited == TRUE))
		return;

	p_mem_restore_vtable ();
}

void
p_mem_shutdown (void)
{
	if (P_UNLIKELY (!p_mem_table_inited))
		return;

	p_mem_table.malloc  = NULL;
	p_mem_table.realloc = NULL;
	p_mem_table.free    = NULL;

	p_mem_table_inited = FALSE;
}

P_LIB_API ppointer
p_malloc (psize n_bytes)
{
	if (P_LIKELY (n_bytes > 0))
		return p_mem_table.malloc (n_bytes);
	else
		return NULL;
}

P_LIB_API ppointer
p_malloc0 (psize n_bytes)
{
	ppointer ret;

	if (P_LIKELY (n_bytes > 0)) {
		if (P_UNLIKELY ((ret = p_mem_table.malloc (n_bytes)) == NULL))
			return NULL;

		memset (ret, 0, n_bytes);
		return ret;
	} else
		return NULL;
}

P_LIB_API ppointer
p_realloc (ppointer mem, psize n_bytes)
{
	if (P_UNLIKELY (n_bytes == 0))
		return NULL;

	if (P_UNLIKELY (mem == NULL))
		return p_mem_table.malloc (n_bytes);
	else
		return p_mem_table.realloc (mem, n_bytes);
}

P_LIB_API void
p_free (ppointer mem)
{
	if (P_LIKELY (mem != NULL))
		p_mem_table.free (mem);
}

P_LIB_API pboolean
p_mem_set_vtable (const PMemVTable *table)
{
	if (P_UNLIKELY (table == NULL))
		return FALSE;

	if (P_UNLIKELY (table->free == NULL || table->malloc == NULL || table->realloc == NULL))
		return FALSE;

	p_mem_table.malloc  = table->malloc;
	p_mem_table.realloc = table->realloc;
	p_mem_table.free    = table->free;

	p_mem_table_inited = TRUE;

	return TRUE;
}

P_LIB_API void
p_mem_restore_vtable (void)
{
	p_mem_table.malloc  = (ppointer (*)(psize)) malloc;
	p_mem_table.realloc = (ppointer (*)(ppointer, psize)) realloc;
	p_mem_table.free    = (void (*)(ppointer)) free;

	p_mem_table_inited = TRUE;
}

P_LIB_API ppointer
p_mem_mmap (psize	n_bytes,
	    PError	**error)
{
	ppointer	addr;
#ifdef P_OS_WIN
	HANDLE		hdl;
#else
	int		fd;
	int		map_flags = MAP_PRIVATE;
#endif

	if (P_UNLIKELY (n_bytes == 0)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IO_INVALID_ARGUMENT,
				     0,
				     "Invalid input argument");
		return NULL;
	}

#ifdef P_OS_WIN
	if (P_UNLIKELY ((hdl = CreateFileMappingA (INVALID_HANDLE_VALUE,
						   NULL,
						   PAGE_READWRITE,
						   0,
						   (DWORD) n_bytes,
						   NULL)) == NULL)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to call CreateFileMapping() to create file mapping");
		return NULL;
	}

	if (P_UNLIKELY ((addr = MapViewOfFile (hdl,
					       FILE_MAP_READ | FILE_MAP_WRITE,
					       0,
					       0,
					       n_bytes)) == NULL)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to call MapViewOfFile() to map file view");
		CloseHandle (hdl);
		return NULL;
	}

	if (P_UNLIKELY (!CloseHandle (hdl))) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to call CloseHandle() to close file mapping");
		UnmapViewOfFile (addr);
		return NULL;
	}
#else
#  if !defined (PLIBSYS_MMAP_HAS_MAP_ANONYMOUS) && !defined (PLIBSYS_MMAP_HAS_MAP_ANON)
	if (P_UNLIKELY ((fd = open ("/dev/zero", O_RDWR | O_EXCL, 0754)) == -1)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to open /dev/zero for file mapping");
		return NULL;
	}
#  else
	fd = -1;
#  endif

#  ifdef PLIBSYS_MMAP_HAS_MAP_ANONYMOUS
	map_flags |= MAP_ANONYMOUS;
#  elif defined (PLIBSYS_MMAP_HAS_MAP_ANON)
	map_flags |= MAP_ANON;
#  endif

	if (P_UNLIKELY ((addr = mmap (NULL,
				      n_bytes,
				      PROT_READ | PROT_WRITE,
				      map_flags,
				      fd,
				      0)) == (void *) -1)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to call mmap() to create file mapping");
#  if !defined (PLIBSYS_MMAP_HAS_MAP_ANONYMOUS) && !defined (PLIBSYS_MMAP_HAS_MAP_ANON)
		if (P_UNLIKELY (p_sys_close (fd) != 0))
			P_WARNING ("PMem::p_mem_mmap: failed to close file descriptor to /dev/zero");
#  endif
		return NULL;
	}

#  if !defined (PLIBSYS_MMAP_HAS_MAP_ANONYMOUS) && !defined (PLIBSYS_MMAP_HAS_MAP_ANON)
	if (P_UNLIKELY (p_sys_close (fd) != 0)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to close /dev/zero handle");
		munmap (addr, n_bytes);
		return NULL;
	}
#  endif
#endif

	return addr;
}

P_LIB_API pboolean
p_mem_munmap (ppointer	mem,
	      psize	n_bytes,
	      PError	**error)
{
	if (P_UNLIKELY (mem == NULL || n_bytes == 0)) {
		p_error_set_error_p (error,
				     (pint) P_ERROR_IO_INVALID_ARGUMENT,
				     0,
				     "Invalid input argument");
		return FALSE;
	}

#ifdef P_OS_WIN
	if (P_UNLIKELY (UnmapViewOfFile (mem) == 0)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to call UnmapViewOfFile() to remove file mapping");
#else
	if (P_UNLIKELY (munmap (mem, n_bytes) != 0)) {
		p_error_set_error_p (error,
				     (pint) p_error_get_last_io (),
				     p_error_get_last_error (),
				     "Failed to call munmap() to remove file mapping");
#endif
		return FALSE;
	} else
		return TRUE;
}
