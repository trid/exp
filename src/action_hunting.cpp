#include "action_hunting.h"

bool ActionHunting::isValid() {
    return actor->getPosition() == "forest";
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
