//
// Created by spsp214 on 1/27/20.
//
#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

using namespace std;

class ClientHandler{
public:
    virtual void handleClient(int inputStream, int outputStream) = 0;
};

#endif //EX4_CLIENTHANDLER_H