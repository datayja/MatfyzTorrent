//
//  du4_thread.h
//  DU4_TORRENT_TRACKER
//
//  Created by Pavel Lisa on 29.4.11.
//  Copyright 2011 MFF UK. All rights reserved.
//

#include <pthread.h>

class Thread {
public:
	Thread();
	virtual ~Thread();
	virtual void wait();
protected: 
	pthread_t thread_id;
	virtual void run(void *args);
	static void entry(Thread *thread);
};
