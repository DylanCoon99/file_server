#include <stdlib.h>
#include <libssh2.h>
#include <sys/socket.h>
#include <iostream>
#include <string>
#include <fstream>
#include "packet.hpp"

class SFTPServer {
    public: 
        // public attributes

        // constructor
        SFTPServer(const std::string& ip, int port);

	// destructor
	~SFTPServer();	

	bool start();
	void stop();
    
    private:
	int serverSocket;
	struct sockaddr_in serverAddr;
        std::string serverIP;
	int serverPort;
	void handleCommand(Command cmd);

	int sendPacket(const Packet& packet);
};


