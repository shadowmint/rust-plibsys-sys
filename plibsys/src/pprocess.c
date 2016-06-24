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

#include "pprocess.h"

#ifndef P_OS_WIN
#  include <sys/types.h>
#  include <signal.h>
#  include <unistd.h>
#endif

P_LIB_API puint32
p_process_get_current_pid (void)
{
#ifdef P_OS_WIN
	return (puint32) GetCurrentProcessId ();
#else
	return (puint32) getpid ();
#endif
}

P_LIB_API pboolean
p_process_is_running (puint32 pid)
{
#ifdef P_OS_WIN
	HANDLE proc;
	DWORD ret;

	if ((proc = OpenProcess (SYNCHRONIZE, FALSE, pid)) == NULL)
		return FALSE;

	ret = WaitForSingleObject (proc, 0);
	CloseHandle (proc);

	return ret == WAIT_TIMEOUT;
#else
	return kill ((pid_t) pid, 0) == 0;
#endif
}
