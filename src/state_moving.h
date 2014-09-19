#include "state.h"

#include <iostream>

using namespace std;

class Actor;

class StateMoving: public State {
public:
    virtual void enter(Actor *actor) { cout << "Start moving" << endl; };
    virtual void execute(Actor *actor);
    virtual void exit(Actor *actor) { cout << "End moving" << endl; };

    static StateMoving* getInstance(){
        static StateMoving instance;
        return &instance;
    }
};