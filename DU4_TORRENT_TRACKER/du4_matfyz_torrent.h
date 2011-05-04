//
//  du4_matfyz_torrent.h
//  DU4_TORRENT_TRACKER
//
//  Created by Pavel Lisa on 28.4.11.
//  Copyright 2011 MFF UK. All rights reserved.
//

#include <string>
#include "du4_sqlite3.h"
#include "du4_thread.h"

class MatfyzTorrent : public Thread {
public:
	MatfyzTorrent();
	~MatfyzTorrent();
	
	void openTorrentFile(const char * &torrent_file_name);
	
	// turn the instance into a tracker
	// means that the instance will keep information about
	// other peers in the swarm, while otherwise it would 
	// throw it away when it doesn't need it anymore
	void setTrackerMode(const bool & mode);
	
	// turn the instance into a leecher/seeder
	// means the instance is interested in storing the shared
	// file locally, but it won't touch already downloaded
	// chunks if we turn this mode off
	void setLeecherMode(const bool & mode);
	
	// tell the instance to shut down gracefully
	void shutDown();
	
	// tell the instance to shut down immediatelly, possible loss of data
	void powerOff();
	
	// tell the instance to disconnect from some IP:port-identified peer and unsubscribe at trackers from that peer
	void disconnectPeer(const std::string & peer_id);
	
	// tell the trackers to reset unsubscribed list
	void resetPeers();
	
	static const int ACTION_NONE = 0;
	static const int ACTION_TRACK_ON = 1;
	static const int ACTION_LEECH_ON = 2;
	static const int ACTION_TRACK_OFF = 3;
	static const int ACTION_LEECH_OFF = 4;
	static const int ACTION_DISCONNECT_PEER = 5;
	static const int ACTION_RESET_PEERS = 6;
	
	static const char *db_name; // set to a file name to use a standard file database
protected:	
	virtual int execute(void *args); // runs in a thread
	
private: 
	pthread_mutex_t torrent_lock;
	sqlite3 *db;
	int next_action;
	
	bool be_tracker;
	bool be_leecher;
};
