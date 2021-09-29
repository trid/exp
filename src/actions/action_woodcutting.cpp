#include "action_woodcutting.h"

bool ActionWoodcutting::isValid() {
    return actor->getPosition() == "forest";
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

ActionWoodcutting::ActionWoodcutting(Actor* actor, World& world) : Action(actor, world) {}
