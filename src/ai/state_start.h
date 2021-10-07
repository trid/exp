#ifndef STATE_START_H
#define STATE_START_H

#include <iostream>

#include "state.h"
#include "actor.h"

namespace Core {
class World;
} // namespace Core

class StateStart: public State {
public:
    StateStart(StateManager& stateManager, Core::World& world);

    void enter(Actor* actor) override;;
    void execute(Actor*) override;
    void exit(Actor* actor) override;;

    void processMessage(Actor *actor, Core::Message &message) override;

private:
    Core::World& _world;
};

#endif