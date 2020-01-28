//
// Created by spsp214 on 1/24/20.
//
#include "CacheManager.h"

FileCacheManager::FileCacheManager(string _fileName) {
    fileName = _fileName;

    string prob, sol;

    ifstream infile(fileName);

    if (infile.good()) {
        while (getline(infile, prob))
        {
            if (!prob.empty()) {
                getline(infile,sol);
                map[prob] = sol;                    //////MAYBE NEED TO REFORMAT SOL AND PROB!!!!!
                //////MAYBE NEED TO REFORMAT SOL AND PROB!!!!!
                //////MAYBE NEED TO REFORMAT SOL AND PROB!!!!!
                //////MAYBE NEED TO REFORMAT SOL AND PROB!!!!!
                //////MAYBE NEED TO REFORMAT SOL AND PROB!!!!!
            }
        }
    }
    infile.close();
}

}

FileCacheManager::~FileCacheManager() {
    ofstream file(fileName);
    for (auto const& pair : map) {
        file << pair.first << endl << pair.second << endl;
    }
    file.close();

}
bool FileCacheManager::doesHaveSol(string _problem) {
    return (map.count(_problem)==1);
}
string FileCacheManager::getSolutionFor(string prob) {
    if(map.count(prob)==0){
        return "Error";
    }
    return map.at(prob);
}
void FileCacheManager::setSol(string prob, string sol) {
    map[prob]=sol;
}

