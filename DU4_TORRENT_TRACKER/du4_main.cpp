//
//  main.cpp
//  DU4_TORRENT_TRACKER
//
//  Created by Pavel Lisa on 20.4.11.
//  Copyright 2011 MFF UK. All rights reserved.
//

#include <iostream>

#include "du4_matfyz_torrent.h"

class TestThread : public Thread {
public: 
	virtual
	int
	execute(void *args) {
		std::cout << (char*) args;
		return 0;
	}
};

int main (int argc, const char * argv[])
{
	Thread *th1 = new TestThread();
	Thread *th2 = new TestThread();
	
	char * m1 = "Thread 1\n";
	char * m2 = "Thread 2\n";
	
	th1->start(m1);
	th2->start(m2);
	
	th1->wait();
	th2->wait();
	
	// insert code here...
	std::cout << "\nHello, World!\n";
	
	char *hname = new char[256];
	int r = gethostname(hname, 256);
	std::cout << "gethostname() = " << r << "\nhname = " << hname << "\n";

    return 0;
}
