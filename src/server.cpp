#include <stdlib.h>
#include <libssh2.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "command.hpp"
#include "sftpserver.hpp"
#include "cache.hpp"
#include <iostream>
#include <string>
#include <fstream>


const uint8_t CACHE_NUM_ENTRIES = 16; // number of entries in the cache


SFTPServer::SFTPServer(const std::string& ip, int port) : serverIP(ip), serverPort(port), serverSocket(-1) {
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(serverPort);
	serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());
		
}


SFTPServer::~SFTPServer() {
	if (serverSocket != -1) {
		close(serverSocket);
	}
}



void SFTPServer::handleCommand(Command cmd) {
	switch (cmd.type) {
        	case CONNECT:
                    // handle case
                case LIST:
                    // handle case
                case CD:
                    // handle case
                case GET:
                    // handle case
                case PUT:
                    // handle case
                case CACHE:
                    // handle case
                case HELP:
                    // handle case
                case EXIT:
                    // handle case
                default:
                    std::cout << "Unknown command" << std::endl;
      }
}


int SFTPServer::sendPacket(const Packet& packet) {
	
	// write the packet data to the socket like a file

	
	return 1;
}



bool SFTPServer::start() {
	
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1) {
		perror("Socket Creation failed");
		return false;
	}

	
	int opt = 1;
	if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
		perror("setsockopt");
		close(serverSocket);
		return false;
	}


	
	if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
		perror("Bind failed");
		close(serverSocket);
		return false;
	}

	if (listen(serverSocket, 5) == -1) {
		perror("Listen failed");
		close(serverSocket);
		return false;
	}

	std::cout << "Server is listening on " << serverIP << ":" << serverPort << std::endl;


	return true;
}


void SFTPServer::stop() {
	if (serverSocket != -1) {
		close(serverSocket);
		serverSocket = -1;
		std::cout << "Server stopped" << std::endl;
	}
}







int main() {

	SFTPServer server("127.0.0.1", 54321);
	
	if (!server.start()) {
		std::cerr << "Failed to start server" << std::endl;
		return 1;
	}
	

	// server.stop();	
	
    	return 0;
}
