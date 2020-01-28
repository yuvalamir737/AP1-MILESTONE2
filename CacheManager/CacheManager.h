//
// Created by spsp214 on 1/24/20.
//

#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
template<class Prob,class Sol>
class CacheManager{
public:
    //do you have a solution for the problem p?
    virtual bool doesHaveSol(Prob p);
    //the func returns the solution for the problem p.
    virtual Sol getSolutionFor(Prob p);
    //set the solution s for the problem p.
    virtual void setSol(Prob p,Sol s);
    virtual ~CacheManager()=default;
};
class FileCacheManager:CacheManager<string,string>{
private:
    unordered_map<string,string> map;
    string fileName;
public:
    // Constructor & Destructor
    explicit FileCacheManager(string _fileName);
    ~FileCacheManager() override;

    // Cache Manager functions
    bool doesHaveSol(string _problem) override;
    string getSolutionFor(string _problem) override;
    void setSol(string _problem, string _solution) override;

};
#endif //MILESTONE2_CACHEMANAGER_H
