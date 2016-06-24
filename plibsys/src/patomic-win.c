/*
 * Copyright (C) 2011 Ryan Lortie <desrt@desrt.ca>
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

#include "patomic.h"

/* Prepare MemoryBarrier() */
#if defined (P_CC_WATCOM) || defined (P_CC_BORLAND)
#  if defined (_M_X64) || defined (_M_AMD64)
#    define MemoryBarrier __faststorefence
#  elseif defined (_M_IA64)
#    define MemoryBarrier __mf
#  else
#    ifdef P_CC_WATCOM
inline
#    else
FORCEINLINE
#    endif /* P_CC_WATCOM */
VOID MemoryBarrier (VOID)
{
	LONG Barrier = 0;
	(void) (Barrier);
	__asm {
		xchg Barrier, eax
	}
}
#  endif /* _M_X64 || _M_AMD64 */
#endif /* P_CC_WATCOM || P_CC_BORLAND */

#if !defined (P_OS_WIN64) && (defined (P_CC_MSVC) && _MSC_VER > 1200)
   /* Tell compiler about intrinsics to suppress warnings,
    * see: https://msdn.microsoft.com/en-us/library/hh977023.aspx */
#  include <intrin.h>
#  define InterlockedAnd _InterlockedAnd
#  define InterlockedOr _InterlockedOr
#  define InterlockedXor _InterlockedXor
#  pragma intrinsic(_InterlockedAnd)
#  pragma intrinsic(_InterlockedOr)
#  pragma intrinsic(_InterlockedXor)
#endif

#if (defined (P_CC_MSVC) && _MSC_VER <= 1200) || defined (P_CC_WATCOM) \
					      || defined (P_CC_BORLAND)
/* Inlined versions for older compilers */
static LONG
ppInterlockedAnd (LONG volatile	*atomic,
		  LONG		val)
{
	LONG i, j;

	j = *atomic;
	do {
		i = j;
		j = InterlockedCompareExchange (atomic, i & val, i);
	} while (i != j);

	return j;
}

#  define InterlockedAnd(a,b) ppInterlockedAnd(a,b)

static LONG
ppInterlockedOr (LONG volatile 	*atomic,
		 LONG		val)
{
	LONG i, j;

	j = *atomic;
	do {
		i = j;
		j = InterlockedCompareExchange (atomic, i | val, i);
	} while (i != j);

	return j;
}

#  define InterlockedOr(a,b) ppInterlockedOr(a,b)

static LONG
ppInterlockedXor (LONG volatile	*atomic,
		  LONG		val)
{
	LONG i, j;

	j = *atomic;
	do {
		i = j;
		j = InterlockedCompareExchange (atomic, i ^ val, i);
	} while (i != j);

	return j;
}

#  define InterlockedXor(a,b) ppInterlockedXor(a,b)
#endif

/* http://msdn.microsoft.com/en-us/library/ms684122(v=vs.85).aspx */

P_LIB_API pint
p_atomic_int_get (const volatile pint *atomic)
{
	MemoryBarrier ();
	return *atomic;
}

P_LIB_API void
p_atomic_int_set (volatile pint	*atomic,
		  pint		val)
{
	*atomic = val;
	MemoryBarrier ();
}

P_LIB_API void
p_atomic_int_inc (volatile pint *atomic)
{
	InterlockedIncrement ((LONG volatile *) atomic);
}

P_LIB_API pboolean
p_atomic_int_dec_and_test (volatile pint *atomic)
{
	return InterlockedDecrement ((LONG volatile *) atomic) == 0 ? TRUE : FALSE;
}

P_LIB_API pboolean
p_atomic_int_compare_and_exchange (volatile pint	*atomic,
				   pint			oldval,
				   pint			newval)
{
	return InterlockedCompareExchange ((LONG volatile *) atomic,
					   (LONG) newval,
					   (LONG) oldval) == oldval;
}

P_LIB_API pint
p_atomic_int_add (volatile pint	*atomic,
		  pint		val)
{
	return (pint) InterlockedExchangeAdd ((LONG volatile *) atomic, (LONG) val);
}

P_LIB_API puint
p_atomic_int_and (volatile puint	*atomic,
		  puint			val)
{
	return (puint) InterlockedAnd ((LONG volatile *) atomic, (LONG) val);
}

P_LIB_API puint
p_atomic_int_or (volatile puint	*atomic,
		 puint		val)
{
	return (puint) InterlockedOr ((LONG volatile *) atomic, (LONG) val);
}

P_LIB_API puint
p_atomic_int_xor (volatile puint	*atomic,
		  puint			val)
{
	return (puint) InterlockedXor ((LONG volatile *) atomic, (LONG) val);
}

P_LIB_API ppointer
p_atomic_pointer_get (const volatile void *atomic)
{
	const volatile ppointer *ptr = (const volatile ppointer *) atomic;

	MemoryBarrier ();
	return *ptr;
}

P_LIB_API void
p_atomic_pointer_set (volatile void	*atomic,
		      ppointer		val)
{
	volatile ppointer *ptr = (volatile ppointer *) atomic;

	*ptr = val;
	MemoryBarrier ();
}

P_LIB_API pboolean
p_atomic_pointer_compare_and_exchange (volatile void	*atomic,
				       ppointer		oldval,
				       ppointer		newval)
{
	return InterlockedCompareExchangePointer ((volatile PVOID *) atomic,
						  (PVOID) newval,
						  (PVOID) oldval) == oldval ? TRUE : FALSE;
}

P_LIB_API pssize
p_atomic_pointer_add (volatile void	*atomic,
		      pssize		val)
{
#if PLIBSYS_SIZEOF_VOID_P == 8
	return (pssize) InterlockedExchangeAdd64 ((LONGLONG volatile *) atomic, (LONGLONG) val);
#else
	return (pssize) InterlockedExchangeAdd ((LONG volatile *) atomic, (LONG) val);
#endif
}

P_LIB_API psize
p_atomic_pointer_and (volatile void	*atomic,
		      psize		val)
{
#if PLIBSYS_SIZEOF_VOID_P == 8
	return (psize) InterlockedAnd64 ((LONGLONG volatile *) atomic, (LONGLONG) val);
#else
	return (psize) InterlockedAnd ((LONG volatile *) atomic, (LONG) val);
#endif
}

P_LIB_API psize
p_atomic_pointer_or (volatile void	*atomic,
		     psize		val)
{
#if PLIBSYS_SIZEOF_VOID_P == 8
	return (psize) InterlockedOr64 ((LONGLONG volatile *) atomic, (LONGLONG) val);
#else
	return (psize) InterlockedOr ((LONG volatile *) atomic, (LONG) val);
#endif
}

P_LIB_API psize
p_atomic_pointer_xor (volatile void	*atomic,
		      psize		val)
{
#if PLIBSYS_SIZEOF_VOID_P == 8
	return (psize) InterlockedXor64 ((LONGLONG volatile *) atomic, (LONGLONG) val);
#else
	return (psize) InterlockedXor ((LONG volatile *) atomic, (LONG) val);
#endif
}

P_LIB_API pboolean
p_atomic_is_lock_free (void)
{
	return TRUE;
}

void
p_atomic_thread_init (void)
{
}

void
p_atomic_thread_shutdown (void)
{
}
