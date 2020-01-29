//
// Created by spsp214 on 1/28/20.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include "ISearcher.h"
#include "ISearchable.h"

class Searcher : public ISearcher<string> {
private:
    ISearchable<string>* curSearchable;
    int evaluatedNodes=0;
public:
    virtual State* popOpenList() = 0;
    virtual bool isOpenListEmpty() = 0;
    virtual void addToOpenList(State* _state) =0;
    virtual vector<State*> backTraceThePath(ISearchable<string>* searchable, State* goal){
        State* node=goal;
        vector<State*> vec;
        vector<State*> finalVec;
        while(!(*node==*(searchable->getInitialState()))){
            vec.push_back(node);
            node=node->getCameFrom();
        }
        vec.push_back(node);
        //now lets reverse the path
        for(int i=0;i<vec.size();i++){
            finalVec[i]=vec.at(vec.size()-i);
        }
        return finalVec;
    }
    vector<State*> search(ISearchable<string>* searchable) override{
        //first we will init the members
        evaluatedNodes=0;
        curSearchable=searchable;
        // now we will insert the initial element in to the open list
        addToOpenList(searchable->getInitialState());
        //while there are still elements in the open list
        while(!isOpenListEmpty()){
            State* curState=popOpenList();
            //if the currents state is the goal one
            if(searchable->isGoal(curState)){
                return backTraceThePath(searchable,curState);
            }
        }
    }

};
#endif //MILESTONE2_SEARCHER_H
