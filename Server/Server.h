//
// Created by spsp214 on 1/27/20.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "../ClientHandler/ClientHandler.h"
using namespace std;

namespace server_side {
    class Server{
    public:
        virtual void open(int port, ClientHandler c) = 0;
        virtual void stop() = 0;
    };
}

#endif //EX4_SERVER_H