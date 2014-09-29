#ifndef STATE_START_H
#define STATE_START_H

#include "iostream"

#include "state.h"
#include "actor.h"

using std::cout;
using std::endl;

class StateStart: public State {
public:
    virtual void enter(Actor*) { cout << "Waked up." << endl;};
    virtual void execute(Actor*);
    virtual void exit(Actor*) { cout << "Start to do something." << endl; };

    virtual void processMessage(Actor *actor, Message &message);

    static State* getInstance() {
        static StateStart state;
        return &state;
    }
};

#endif