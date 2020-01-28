//
// Created by spsp214 on 1/27/20.
//
#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"
using namespace std;

class MySerialServer : public server_side::Server{
public:
    bool stopLoop;
    MySerialServer(){this->stopLoop = false;}
    virtual void open(int port, ClientHandler c);
    virtual void stop();
    void clientsLoop(int socketfd, sockaddr_in &address, ClientHandler &c);
};
#endif //EX4_MYSERIALSERVER_H