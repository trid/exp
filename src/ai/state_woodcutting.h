#include "state.h"
#include "../world.h"

#include <iostream>

using namespace std;

class StateWoodcutting: public State {
public:
    StateWoodcutting(StateManager& stateManager, World& world);

    void enter(Actor* actor) override;
    void execute(Actor* actor) override;
    void exit(Actor* actor) override;
    void processMessage(Actor *actor, Message &message) override;

private:
    World& _world;
};

