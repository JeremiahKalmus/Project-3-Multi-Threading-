/**
 * @file mdat.h
 * @brief MDAT library interface functions
 *
 * This file contains the external library functions for MDAT.
 */

/*  Copyright (C) 2013  Eric Larson and Rochelle Palting
    elarson@seattleu.edu

    This file is part of the MDAT infrastructure.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MDAT_H
#define MDAT_H

#ifdef __cplusplus
extern "C" {
#endif 

#include <semaphore.h>
#include <pthread.h>

/**
 * @typedef typedef const char *(*CheckerFuncPtr)(int, const char *, const char *);
 * @brief Function pointer type for checker function
 *
 * See the CheckerWrapper documentation for more on the checker callback function.
 */
typedef const char *(*CheckerFuncPtr)(int, const char *, const char *);

// ************************
// INITIALIZATION FUNCTIONS
// ************************

/**
 *  @brief Initializes MDAT library.
 *
 *  This function initializes the MDAT library.  The application must call
 *  @ref mdat_init before calling any other functions.
 *
 *  @param[in]	numThreads	Number of threads that will concurrently executing.
 *  @param[in]  traceName	Name of the output trace file.  Set to NULL to
 *  suppress tracing.
 *  @param[in]	checkerFunc	Program-specific checker. Set to NULL for no checker.
 *  @param[in]	useInteractive	If nonzero (true), interactive scheduling is used.
 *  Otherwise, random scheduling is used.
 *  @param[in]	useSeed		If nonzero (true), use the seed parameter as the
 *  random seed.  If zero (false), generate a random seed based on the current time.
 *  This parameter is ignored if interactive scheduling is used.
 *  @param[in]	seed		The specified random seed.  This parameter is
 *  ignored if interactive scheduling is used or if useSeed is zero.
 */ 
void mdat_init(int numThreads, char *traceName, CheckerFuncPtr checkerFunc,
      int useInteractive, int useSeed, unsigned int seed);

// ****************
// THREAD FUNCTIONS
// ****************

/**
 *  @brief Starts a thread.
 * 
 *  This function registers a thread with MDAT.  This function must be called
 *  before a thread makes any synchronization calls.  MDAT takes over the
 *  scheduling of the thread in this function – threads may wait in this
 *  function until they are dispatched by MDAT.
 *
 *  @param[in]	id		Id number. Each thread must have a unique
 *  number from 0 to n-1 where n is the number of threads.
 *  @param[in]	property	String indicating the type of thread. For
 *  example, in the reader-writers problem, some threads will have the
 *  property “reader” and other threads will have the property “writer”.
 */  
void mdat_thread_start(int id, const char *property);

/**
 *  @brief Mark the currently running thread as completed.
 * 
 *  Marks the currently running thread as complete – the thread will no
 *  longer be scheduled by MDAT.  Threads cannot be restarted once they
 *  have finished.
 */ 
void mdat_thread_finish();

/**
 *  @brief Invokes the scheduler, possibly causing a new thread to run.
 * 
 *  Forces MDAT to make a scheduling decision based on the scheduling mode
 *  (see ThreadManager for more details).  This call could be inserted
 *  manually by the programmer or inserted automatically by the
 *  instrumentation tool (recommended).
 *
 *  @param[in] location		An id associated with the call. This
 *  parameter is used to update the location field in the trace. It is
 *  recommended but not required to have each location be unique. (Note:
 *  Only use positive integers as negative integers are used for calls
 *  internal to MDAT.)
 */ 
void mdat_invoke_scheduler(int location);

// **************
// LOCK FUNCTIONS
// **************

/**
 *  @brief Registers a new mutex lock.
 * 
 *  Registers a new mutex lock with the LockManager.
 *
 *  @param[in] name		name of the lock
 *  @param[in] lock		lock variable
 *  @param[in] attr		lock attributes (ignored by MDAT)
 */ 
void mdat_mutex_init(const char *name, pthread_mutex_t *lock,
        pthread_mutexattr_t *attr);

/**
 *  @brief Implements the lock operation.
 *  
 *  Thread takes a lock if available.  If the lock is unavailable,
 *  the thread will wait until it acquires the lock.
 * 
 *  @param[in] lock		lock variable
 */ 
void mdat_mutex_lock(pthread_mutex_t *lock);

/**
 *  @brief Implements the unlock operation.
 *
 *  Gives up the lock. If one or more threads are waiting, one thread
 *  will be woken up and given the lock. If no threads are waiting,
 *  the lock is returned to the unlocked state.
 * 
 *  @param[in] lock		lock variable
 */  
void mdat_mutex_unlock(pthread_mutex_t *lock);

// *******************
// SEMAPHORE FUNCTIONS
// *******************

/**
 *  @brief Registers a new semaphore.
 *
 *  Registers a new semaphore with the Semaphore Manager
 * 
 *  @param[in]	name		name of the semaphore
 *  @param[in]	sem		semaphore variable
 *  @param[in]	pshared		sharing value (ignored by MDAT)
 *  @param[in]	value		initial value of semaphore
 */  
void mdat_sem_init(const char *name, sem_t *sem, int pshared, int value);

/**
 *  @brief Implements the wait operation for a semaphore.
 *
 *  Decrement the semaphore. If the value is negative, the thread
 *  must wait until woken up by a subsequent post operation.
 * 
 *  @param[in]	sem		semaphore variable
 */ 
void mdat_sem_wait(sem_t *sem);

/**
 *  @brief Implements the post operation for a semaphore.
 *
 *  Increment the semaphore. If one or more threads are waiting, one
 *  thread will be woken up.
 * 
 *  @param[in]	sem		semaphore variable
 */ 
void mdat_sem_post(sem_t *sem);

// *****************
// SECTION FUNCTIONS
// *****************

/**
 *  @brief Enters the specific section
 * 
 *  Records that a thread has entered a particular section of the code.
 *  In addition, it notifies the checker that the current thread has
 *  entered the appropriate section.
 *
 *  @param[in]	section		The section that the thread has entered.
 *  Common sections include “Entry”, “Exit”, “Critical”, and “Remainder”.
 *  Note that you do not have to use these particular sections – any set of
 *  strings will so as long the strings are recognized by the checker.
 */ 
void mdat_enter_section(const char *section);

#ifdef __cplusplus
}
#endif 

#endif
