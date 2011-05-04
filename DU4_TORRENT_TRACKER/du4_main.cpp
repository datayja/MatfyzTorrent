//
//  main.cpp
//  DU4_TORRENT_TRACKER
//
//  Created by Pavel Lisa on 20.4.11.
//  Copyright 2011 MFF UK. All rights reserved.
//

#include <iostream>
#include <string>

#include "du4_matfyz_torrent.h"

int main (int argc, const char **argv)
{
	std::cout << "\nHello, User!\n";
	
	if (argc > 1) {
		// array of torrents
		MatfyzTorrent *torrents[argc-1];
		
		for (int i = 1; i < argc; i++) {
			
			// create a new torrent instance
			torrents[i] = new MatfyzTorrent();
			torrents[i]->openTorrentFile(argv[i]);
			
			std::string actions;
			
			bool allset = false;
			while (!allset) {
				std::cout << "Torrent #" << i << " (" << argv[i] << ") actions: ";
				
				std::getline(std::cin, actions);
				if (actions == "leech") {
					torrents[i]->setLeecherMode(true);
					allset = true;
				} else if (actions == "track") {
					torrents[i]->setTrackerMode(true);
					allset = true;
				} else if (actions == "track and leech") {
					torrents[i]->setLeecherMode(true);
					torrents[i]->setTrackerMode(true);
					allset = true;
				} else if (actions == "help" || actions == "?") {
					std::cout	<< "Available options:\n\t"
								<< "\"leech\" - download the torrent\n\t"
								<< "\"track\" - enable tracking\n\t" 
								<< "\"track and leech\" - download the torrent and track it as well\n"
								<< "You may add other actions later.\n";
				} else {
					std::cerr << "Unknown command, try a different one or type help\n";
				}
			}
			
			// execute the thread
			torrents[i]->start(0);
		}
	}
	
	/*char *hname = new char[256];
	int r = gethostname(hname, 256);
	std::cout << "gethostname() = " << r << "\nhname = " << hname << "\n";*/

    return 0;
}
