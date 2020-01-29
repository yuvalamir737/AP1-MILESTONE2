//
// Created by spsp214 on 1/28/20.
//

#ifndef MILESTONE2_ISEARCHABLE_H
#define MILESTONE2_ISEARCHABLE_H

#include <set>
#include "State.h"
using namespace std;
template <class T>
class ISearchable{
public:
    virtual ~ISearchable() = default;
    virtual State* getInitialState() = 0;
    virtual bool isGoal(State*) = 0;
    virtual set<State*> getAllPossibleStates(State*) = 0;
};
#endif //MILESTONE2_ISEARCHABLE_H
