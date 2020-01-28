//
// Created by spsp214 on 1/27/20.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "../Solver.h"
#include "../CacheManager/CacheManager.h"
using namespace std;

class MyTestClientHandler : public ClientHandler {
    Solver<string,string>* solver;
    FileCacheManager* fileCacheManager;

public:
    //inputStream
    void handleClient(int inputStream, int outputStream) ;

    MyTestClientHandler(FileCacheManager* fileCacheManager1,Solver<string,string>* solver1) ;


};

#endif //EX4_MYTESTCLIENTHANDLER_H