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

/**
 * @file pcondvariable.h
 * @brief Condition variable
 * @author Alexander Saprykin
 *
 * A condition variable is an inter-thread synchronization primitive, often
 * used in the classical 'producers-consumers' concurrent data access models.
 *
 * The main idea is to notify waiting thread(s) for some events before they
 * can enter a critical section. Hence the name of the primitive: a thread
 * enters the critical section upon an accomplished condition. Compare it with a
 * mutex where the thread enters the critical section as soon as no one holds a
 * lock.
 *
 * Several threads can be notified at once, but only one of them can enter the
 * critical section. The order of the threads in that case is implementation
 * dependent.
 *
 * As the thread enters the critical section upon a condition it still requires
 * a mutex to guard its code against concurrent access from other threads. The
 * mutex provided in pair with a condition variable will be automatically locked
 * on the condition, the thread should unlock it explicitly after leaving the
 * critical section. That mutex is unlocked while waiting for the condition and
 * should be locked prior calling the condition waiting routine.
 *
 * The waiting thread behavior: create a new condition variable with
 * p_cond_variable_new(), create and lock a mutex before a critical section and
 * wait for a signal from another thread on this condition variable
 * using p_cond_variable_wait().
 *
 * The signaling thread behavior: upon reaching event time emit a signal with
 * p_cond_variable_signal() to wake up a single waiting thread or
 * p_cond_variable_broadcast() to wake up all the waiting threads.
 *
 * After emitting the signal only the one thread will get the locked mutex back
 * to continue executing the critical section.
 *
 * It is implementation dependent whether a thread will receive a missed signal
 * (when a notification from the one thread was emitted prior another thread has
 * been called for waiting), so do not rely on this behavior.
 */

#if !defined (PLIBSYS_H_INSIDE) && !defined (PLIBSYS_COMPILATION)
#  error "Header files shouldn't be included directly, consider using <plibsys.h> instead."
#endif

#ifndef PLIBSYS_HEADER_PCONDVARIABLE_H
#define PLIBSYS_HEADER_PCONDVARIABLE_H

#include "pmacros.h"
#include "ptypes.h"
#include "pmutex.h"

P_BEGIN_DECLS

/** Condition variable opaque data structure. */
typedef struct PCondVariable_ PCondVariable;

/**
 * @brief Creates a new #PCondVariable.
 * @return Pointer to a newly created #PCondVariable structure, or NULL if
 * failed.
 * @since 0.0.1
 */
P_LIB_API PCondVariable *	p_cond_variable_new		(void);

/**
 * @brief Frees #PCondVariable structure.
 * @param cond Condtion variable to free.
 * @since 0.0.1
 */
P_LIB_API void			p_cond_variable_free		(PCondVariable	*cond);

/**
 * @brief Waits for a signal on a given condition variable.
 * @param cond Condition variable to wait on.
 * @param mutex Locked mutex which will remain locked after waiting.
 * @return TRUE on success, FALSE otherwise.
 * @since 0.0.1
 *
 * The calling thread will sleep until the signal on @a cond arrived.
 */
P_LIB_API pboolean		p_cond_variable_wait		(PCondVariable	*cond,
								 PMutex		*mutex);

/**
 * @brief Emitts a signal on a given condition variable for one waiting thread.
 * @param cond Condition variable to emit the signal on.
 * @return TRUE on success, FALSE otherwise.
 * @since 0.0.1
 *
 * After emitting the signal only the one thread waiting for it will be waken
 * up. Do not rely on a queue concept for waiting threads. Though the
 * implementation is intended to be much close to a queue, it's not fairly
 * enough. Due that any thread can be waken up, even if it has just called
 * p_cond_variable_wait() while there are other waiting threads.
 */
P_LIB_API pboolean		p_cond_variable_signal		(PCondVariable	*cond);

/**
 * @brief Emitts a signal on a given condition variable for all the waiting
 * threads.
 * @param cond Condition variable to emit the signal on.
 * @return TRUE on success, FALSE otherwise.
 * @since 0.0.1
 *
 * After emitting the signal all the threads waiting for it will be waken up.
 */
P_LIB_API pboolean		p_cond_variable_broadcast	(PCondVariable	*cond);

P_END_DECLS

#endif /* PLIBSYS_HEADER_PCONDVARIABLE_H */
