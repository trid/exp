#include "action_woodcutting.h"

#include "../ai/constants.h"

#include "constants.h"

namespace Core::Actions {

bool ActionWoodcutting::isValid() {
    return actor->getPosition() == Core::AI::kForestLocationName;
}

void ActionWoodcutting::update(int delta) {
    time += delta;
    if (time >= interval) {
        time -= interval;
        actor->addItem(kItemWood);
    }
}

int ActionWoodcutting::progress() {
    return 0;
}

bool ActionWoodcutting::isFinished() {
    return false;
}

ActionWoodcutting::ActionWoodcutting(AI::Actors::Agent* actor, Core::World& world) :
        Action(actor, world),
        interval(kWoodcuttingTime) {}

} // namespace Core::Actions