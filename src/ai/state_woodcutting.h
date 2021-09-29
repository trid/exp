#include "state.h"
#include "../world.h"

#include <iostream>

using namespace std;

class StateWoodcutting: public State {
public:
    StateWoodcutting(StateManager& stateManager, World& world);

    virtual void enter(Actor* actor);
    virtual void execute(Actor* actor);
    virtual void exit(Actor* actor);
    virtual void processMessage(Actor *actor, Message &message) override;

private:
    World& _world;
};

