#include <stdlib.h>
#include <libssh2.h>
#include <libssh2_sftp.h>
#ifdef __WIN32__
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#endif
#include <iostream>
#include <string>
#include <fstream>


class SFTPClient {
    public: 
        // public attributes
        SOCKADDR clientIP; // use IPv4?
        // SOCKET clientSocket;

        /*

        struct sockaddr_in {
            short sin_family;        // Address family (AF_INET for IPv4)
            unsigned short sin_port; // Port number (in network byte order)
            struct in_addr sin_addr;
            char sin_zero[8];        // Padding to make the structure the same size as sockaddr
};
        */

        // constructor
        SFTPClient();

        // public methods
        int connect(SOCKADDR serverIP);
        
    
    private:
        // private attributes

};


SFTPClient::SFTPClient() {
    
    // I need to programmatically assign the clientIP attribute

    //clientIP.sin_addr = 172.23.166.180;

}


int SFTPClient::connect(SOCKADDR serverIP) {
    // takes in a server ip address as input
    // established connection over TCP/SSH 
    // by creating a socket

    // prompt user for username and password

    // returns 1 on failure; returns 0 on success

    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }




}


int main() {


    // create an instance of the SFTP Client and wait for user to enter commands


    return 0;
}