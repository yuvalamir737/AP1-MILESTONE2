//
// Created by spsp214 on 1/28/20.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <string>
using namespace std;
class State {
private:
    string state;
    double cost;
    State* cameFrom = nullptr;
//    bool inSolution = false;
public:

    /* delete all chain of states from the heap (if allocated there)
    static void deleteStateChain(State* state){
        State* prevState;
        //while there are more states to go over
        while (state != nullptr) {
            prevState = state->getCameFrom();
            delete state;
            state = prevState;
        }
    }*/

    State(string _state, double _cost, State* _cameFrom)
    {
        state = _state;
        cost = _cost;
        cameFrom = _cameFrom;
    }
    ~State() {  }

    // Getters & setters
    string getState(){
        return state;
    }
    double getCost(){
        return cost;
    }
    void setCost(double _cost){
        cost = _cost;
    }
    State* getCameFrom(){
        return cameFrom;
    }
    void setCameFrom(State* _cameFrom){
        cameFrom=_cameFrom;
    }

    // Helpers
//    void toggleInSolution();
//    bool isInSolution();

    // Operators
    bool operator==(State& rhs){
        return (    (this->state).compare(rhs.getState()) == 0);
    }
};






/*template <class T>
void State<T>::toggleInSolution() {
    inSolution = !inSolution;
}

template <class T>
bool State<T>::isInSolution() {
    return inSolution;
}*/
#endif //MILESTONE2_STATE_H
