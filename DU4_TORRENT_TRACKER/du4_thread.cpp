//
//  du4_thread.cpp
//  DU4_TORRENT_TRACKER
//
//  Created by Pavel Lisa on 29.4.11.
//  Copyright 2011 MFF UK. All rights reserved.
//

#include "du4_thread.h"

// class Thread

Thread::Thread():running(false) {}

Thread::~Thread() {}

int 
Thread::start(void *args) {
	this->running = true;
	this->return_value = new int(Thread::ERROR);
	return pthread_create( 
						  &(this->thread_id), 0, // pointer to pthread_t
						  Thread::entry, // pointer to static entry method
						  new ThreadArgs(args, this) // pointer to a ThreadArgs
	);
}

int
Thread::wait() {
	if (running) {
		pthread_join( this->thread_id, &(this->return_value));
	
		this->running = false;
	} 
	// cast void* to int* and dereference
	return *((int*)(this->return_value));
}

void
Thread::cancel() {
	if (running) {
		// give the thread a chance to cancel it's children
		this->threadWillBeCancelled();
		
		pthread_cancel(this->thread_id);
		this->running = false;
	}
}

int
Thread::run(void * args) {
	return this->execute(args);
}

// static
void *
Thread::entry(void *args) {
	// extract thread pointer from the args
	ThreadArgs *thread_args = (ThreadArgs *) args;
	Thread *thread = (Thread *) thread_args->getThread();
	
	// and run the thread's main (virtual) method
		
	void * ret_val = new int(thread->run(thread_args->getArgs()));
	
	return ret_val;
}

// class ThreadArgs

ThreadArgs::ThreadArgs(void *thread_args_in, Thread *thread_in) {
	this->thread_args = thread_args_in;
	this->thread = thread_in;
}

void *
ThreadArgs::getArgs() const {
	return this->thread_args;
}

Thread *
ThreadArgs::getThread() const {
	return this->thread;
}
