#include "state.h"

#include <iostream>

namespace Core {
class World;
} // namespace Core

class StateWoodcutting: public State {
public:
    StateWoodcutting(StateManager& stateManager, Core::World& world);

    void enter(Actor* actor) override;
    void execute(Actor* actor) override;
    void exit(Actor* actor) override;
    void processMessage(Actor *actor, Core::Message &message) override;

private:
    Core::World& _world;
};

