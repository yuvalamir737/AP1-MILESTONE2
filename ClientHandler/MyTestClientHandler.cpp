//
// Created by spsp214 on 1/28/20.
//
#include "MyTestCLientHandler.h"

void handleClient(int inputStream, int outputStream) {

}

MyTestClientHandler::MyTestClientHandler(FileCacheManager *fileCacheManager1, Solver<string, string> *solver1) {
    fileCacheManager = fileCacheManager1;
    solver = solver1;
}

