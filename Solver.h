//
// Created by spsp214 on 1/24/20.
//

#ifndef MILESTONE2_SOLVER_H
#define MILESTONE2_SOLVER_H
#include <string>
using namespace std;
template<class Prob, class Sol>
class Solver {
public:
    // pure virtual function
    virtual Sol solve(Prob problem) = 0;


};

class StringReverser:public Solver <string,string>{
public:
    string solve(string problem){
        string s="";
        //iterating the problem string in the opposite order
        for(int i=problem.size()-1;i>=0;i--){
            s=s+problem.at(i);
        }
        return s;
    }
};


#endif //MILESTONE2_SOLVER_H
