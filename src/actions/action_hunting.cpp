#include "action_hunting.h"

#include "../ai/constants.h"

#include "constants.h"

bool ActionHunting::isValid() {
    return actor->getPosition() == kForestLocationName;
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

ActionHunting::ActionHunting(Actor* actor, Core::World& world):
    Action(actor, world),
    interval(kActionHuntTime) { }
