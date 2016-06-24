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

#include "pmutex.h"

#include <stdlib.h>

struct PMutex_ {
	pint	hdl;
};

P_LIB_API PMutex *
p_mutex_new (void)
{
	return NULL;
}

P_LIB_API pboolean
p_mutex_lock (PMutex *mutex)
{
	return FALSE;
}

P_LIB_API pboolean
p_mutex_trylock (PMutex *mutex)
{
	P_UNUSED (mutex);

	return FALSE;
}

P_LIB_API pboolean
p_mutex_unlock (PMutex *mutex)
{
	P_UNUSED (mutex);

	return FALSE;
}

P_LIB_API void
p_mutex_free (PMutex *mutex)
{
	P_UNUSED (mutex);
}
