/*
 * Copyright (C) 2016 Alexander Saprykin <xelfium@gmail.com>
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
#include "prwlock.h"

#include <stdlib.h>
#include <thread.h>

typedef rwlock_t rwlock_hdl;

struct PRWLock_ {
	rwlock_hdl hdl;
};

static pboolean pp_rwlock_unlock_any (PRWLock *lock);

static pboolean
pp_rwlock_unlock_any (PRWLock *lock)
{
	if (P_UNLIKELY (lock == NULL))
		return FALSE;

	if (P_LIKELY (rw_unlock (&lock->hdl) == 0))
		return TRUE;
	else {
		P_ERROR ("PRWLock::pp_rwlock_unlock_any: rw_unlock() failed");
		return FALSE;
	}
}

P_LIB_API PRWLock *
p_rwlock_new (void)
{
	PRWLock *ret;

	if (P_UNLIKELY ((ret = p_malloc0 (sizeof (PRWLock))) == NULL)) {
		P_ERROR ("PRWLock::p_rwlock_new: failed to allocate memory");
		return NULL;
	}

	if (P_UNLIKELY (rwlock_init (&ret->hdl, USYNC_THREAD, NULL) != 0)) {
		P_ERROR ("PRWLock::p_rwlock_new: rwlock_init() failed");
		p_free (ret);
		return NULL;
	}

	return ret;
}

P_LIB_API pboolean
p_rwlock_reader_lock (PRWLock *lock)
{
	if (P_UNLIKELY (lock == NULL))
		return FALSE;

	if (P_UNLIKELY (rw_rdlock (&lock->hdl) == 0))
		return TRUE;
	else {
		P_ERROR ("PRWLock::p_rwlock_reader_lock: rw_rdlock() failed");
		return FALSE;
	}
}

P_LIB_API pboolean
p_rwlock_reader_trylock (PRWLock *lock)
{
	if (P_UNLIKELY (lock == NULL))
		return FALSE;

	return (rw_tryrdlock (&lock->hdl) == 0) ? TRUE : FALSE;
}

P_LIB_API pboolean
p_rwlock_reader_unlock (PRWLock *lock)
{
	return pp_rwlock_unlock_any (lock);
}

P_LIB_API pboolean
p_rwlock_writer_lock (PRWLock *lock)
{
	if (P_UNLIKELY (lock == NULL))
		return FALSE;

	if (P_UNLIKELY (rw_wrlock (&lock->hdl) == 0))
		return TRUE;
	else {
		P_ERROR ("PRWLock::p_rwlock_writer_lock: rw_wrlock() failed");
		return FALSE;
	}
}

P_LIB_API pboolean
p_rwlock_writer_trylock (PRWLock *lock)
{
	if (P_UNLIKELY (lock == NULL))
		return FALSE;

	return (rw_trywrlock (&lock->hdl) == 0) ? TRUE : FALSE;
}

P_LIB_API pboolean
p_rwlock_writer_unlock (PRWLock *lock)
{
	return pp_rwlock_unlock_any (lock);
}

P_LIB_API void
p_rwlock_free (PRWLock *lock)
{
	if (P_UNLIKELY (lock == NULL))
		return;

	if (P_UNLIKELY (rwlock_destroy (&lock->hdl) != 0))
		P_ERROR ("PRWLock::p_rwlock_free: rwlock_destroy() failed");

	p_free (lock);
}

void
p_rwlock_init (void)
{
}

void
p_rwlock_shutdown (void)
{
}
