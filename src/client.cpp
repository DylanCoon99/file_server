#include <stdlib.h>
#include <libssh2.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "command.h"

#include <iostream>
#include <string>
#include <fstream>


SFTPClient::SFTPClient() {
    
    // I need to programmatically assign the clientIP attribute

    //clientIP.sin_addr = 172.23.166.180;

}


~SFTPClient::SFTPClient() {
	
}

int SFTPClient::connect(SOCKADDR serverIP) {
    // takes in a server ip address as input
    // established connection over TCP/SSH 
    // by creating a socket

    // prompt user for username and password

    // returns 1 on failure; returns 0 on success

}





int main() {


    // create an instance of the SFTP Client and wait for user to enter commands


    return 0;
}
