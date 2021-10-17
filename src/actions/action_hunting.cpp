#include "action_hunting.h"

#include "../ai/constants.h"
#include "../ai/actors/agent.h"

#include "constants.h"

namespace Core::Actions {

bool ActionHunting::isValid() {
    return actor->getPosition() == Core::AI::kForestLocationName;
}

void ActionHunting::update(int delta) {
    time += delta;
    if (time >= interval) {
        time -= interval;
        actor->addItem();
    }
}

int ActionHunting::progress() {
    return 0;
}

bool ActionHunting::isFinished() {
    return false;
}

ActionHunting::ActionHunting(AI::Actors::Agent* actor, Core::World& world) :
        Action(actor, world),
        interval(kActionHuntTime) {}

} // namespace Core::Actions