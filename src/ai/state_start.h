#ifndef STATE_START_H
#define STATE_START_H

#include <iostream>

#include "state.h"
#include "actor.h"

using std::cout;
using std::endl;

class StateStart: public State {
public:
    StateStart(StateManager& stateManager, World& world);

    void enter(Actor* actor) override;;
    void execute(Actor*) override;
    void exit(Actor* actor) override;;

    void processMessage(Actor *actor, Message &message) override;

private:
    World& _world;
};

#endif