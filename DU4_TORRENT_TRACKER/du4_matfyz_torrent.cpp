//
//  du4_matfyz_torrent.cpp
//  DU4_TORRENT_TRACKER
//
//  Created by Pavel Lisa on 28.4.11.
//  Copyright 2011 MFF UK. All rights reserved.
//

#include "du4_matfyz_torrent.h"
#include <iostream>
#include <fstream>

// this can be set to a file name to use a more permanent database storage,
// not only runtime-only
const char *MatfyzTorrent::db_name = ":memory:";

MatfyzTorrent::MatfyzTorrent():
	next_action(MatfyzTorrent::ACTION_NONE), 
	be_leecher(false), 
	be_tracker(false),
	db(0) 
{
	int res = sqlite3_open(MatfyzTorrent::db_name, &db);
	if (res != SQLITE_OK) {
		std::cerr << "Could not open an in-memory database. Exiting.\n";
		exit(res);
	}
}

MatfyzTorrent::~MatfyzTorrent() {
	int res = sqlite3_close(db); // free resources
	if (res != SQLITE_OK) {
		std::cerr << "Error closing an in-memory database.\n";
	}
	// delete db; - gives a warning about deleting an incomplete type
}

void
MatfyzTorrent::openTorrentFile(const char *&torrent_file_name) {
	std::ifstream torrent_file(torrent_file_name);
}

int
MatfyzTorrent::execute(void *args) {
	/*
	 basically, this thread just waits for signals from the 
	 controlling thread and executes them:
	 */
	
	return 0;
}

void
MatfyzTorrent::setTrackerMode(const bool &mode) {

}

void 
MatfyzTorrent::setLeecherMode(const bool &mode) {
	
}

void
MatfyzTorrent::shutDown() {
	
}

void 
MatfyzTorrent::powerOff() {
	
}
