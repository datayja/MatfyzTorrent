//
//  du4_thread.h
//  DU4_TORRENT_TRACKER
//
//  Created by Pavel Lisa on 29.4.11.
//  Copyright 2011 MFF UK. All rights reserved.
//

#include <pthread.h>

// dumb class to make multithreaded code prettier
class Thread {
public:
	Thread();
	virtual ~Thread();
	int wait();
	void cancel();
	int start(void *args);
	
	static const int OK = 0;
	static const int ERROR = 1;
protected: 
	pthread_t thread_id;
	bool running; // helper flag to prevent error conditions (cancelling a non-running thread...)
	void *stored_args;
	void *return_value;
	static void *entry(void *args); // helper static method, run first
	int run(void *args); // helper method runs virtual method
	virtual int execute(void *args) = 0; // main method, override
	
	virtual void threadWillBeCancelled(void) = 0; // a message that all children threads should be cancelled as well
};

// dumb class to bridge real arguments for the threaded function and the thread pointer
class ThreadArgs {
public: 
	ThreadArgs(void *thread_args_in, Thread *thread_in);
	void* getArgs() const;
	Thread* getThread() const;
private: 
	void *thread_args;
	Thread *thread;
};
