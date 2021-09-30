#include "action_woodcutting.h"

#include "../ai/constants.h"

#include "constants.h"

bool ActionWoodcutting::isValid() {
    return actor->getPosition() == kForestLocationName;
}

void ActionWoodcutting::update(int delta) {
    time += delta;
    if (time >= interval) {
        time -= interval;
        actor->addItem();
    }
}

int ActionWoodcutting::progress() {
    return 0;
}

bool ActionWoodcutting::isFinished() {
    return false;
}

ActionWoodcutting::ActionWoodcutting(Actor* actor, World& world) :
    Action(actor, world),
    interval(kWoodcuttingTime) {}
