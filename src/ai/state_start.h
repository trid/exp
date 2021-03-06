#ifndef STATE_START_H
#define STATE_START_H

#include "iostream"

#include "state.h"
#include "actor.h"

using std::cout;
using std::endl;

class StateStart: public State {
public:
    virtual void enter(Actor* actor) { actor->say("Waked up.");};
    virtual void execute(Actor*);
    virtual void exit(Actor* actor) { actor->say("Start to do something."); };

    virtual void processMessage(Actor *actor, Message &message);

    static State* getInstance() {
        static StateStart state;
        return &state;
    }
};

#endif