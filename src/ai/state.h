#ifndef STATE_H
#define STATE_H

#include <memory>
#include "actor.h"

class Actor;
class StateManager;

class State {
public:
    State(StateManager& stateManager);

    virtual void enter(Actor *) = 0;
    virtual void execute(Actor *) = 0;
    virtual void exit(Actor *) = 0;
    virtual void processMessage(Actor *actor, Message &message) = 0;

protected:
    StateManager& getStateManager();

private:
    StateManager& _stateManager;
};

#endif