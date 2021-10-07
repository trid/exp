#include <iostream>

#include "actor.h"

namespace Core::AI {

class StateFinished : public State {
public:
    explicit StateFinished(StateManager& stateManager);

    void enter(Actor* actor) override;
    void execute(Actor* actor) override;
    void exit(Actor* actor) override;

    void processMessage(Actor* actor, Core::Message& message) override;
};

} // namespace AI