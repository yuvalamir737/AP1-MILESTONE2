//
// Created by spsp214 on 1/27/20.
//
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "MySerialServer.h"
using namespace std;

void MySerialServer::open(int port, ClientHandler c) {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return ;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    //the actual bind command
    if (::bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
        return;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        return;
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }


    struct timeval tv;
    tv.tv_sec = 120;
    tv.tv_usec = 0;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    clientsLoop(socketfd, address, c);

    close(socketfd);

}

void MySerialServer::clientsLoop(int socketfd, sockaddr_in &address, ClientHandler &c) {

    while (!stopLoop) {

        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *)&address, (socklen_t*)&address);

        if(client_socket < 0) {
            //time out
            if (errno == EWOULDBLOCK) {
                close(client_socket);
                stop();
                continue;
                //error
            } else{
                cerr<<"Error accepting client"<<std::endl;
                return;
            }

        }

        c.handleClient(client_socket,client_socket);
        close(client_socket);
    }
}


void MySerialServer::stop() {
    this->stopLoop = true;
}
