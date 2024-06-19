#include <stdlib.h>
#include <libssh2.h>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include <fstream>
#include "packet.hpp"


class SFTPClient {
    public: 
        // public attributes
	
	//constructor
	SFTPClient(const std::string& ip, int port);
    
	// destructor
	~SFTPClient();

	

    private:
        // private attributes

	int clientSocket;
	struct sockaddr_in clientAddr;
	std::string clientIP;
	int clientPort;
	void sendPacket(const Packet& packet);
	
};


