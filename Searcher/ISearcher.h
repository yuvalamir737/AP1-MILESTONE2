//
// Created by spsp214 on 1/28/20.
//

#ifndef MILESTONE2_ISEARCHER_H
#define MILESTONE2_ISEARCHER_H
#include "ISearchable.h"
#include "State.h"
#include "Solver.h"
#include <vector>

template <class T>
class ISearcher {

public:
    virtual ~ISearcher() = default;
    virtual vector<State*> search (ISearchable<T>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;

    // Clone method: stateless - should return self, stateful - should return a clone of self
    virtual ISearcher* clone() = 0;
    // void markSolutionPath(State<T>* _goal);
};
#endif //MILESTONE2_ISEARCHER_H
