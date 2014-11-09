#include "action_eating.h"
#include "world.h"

bool ActionEating::isValid() {
    return actor->getPosition() == "home";
}

void ActionEating::update(int delta) {
    time += delta;
    if (time >= maxTime) {
        time = maxTime;
        actor->setFood(90);
        actor->removeGlobalState("hungry");
        World::getWorld().removeFood();
        stop();
    }
}

int ActionEating::progress() {
    return time * 100 / maxTime;;
}

bool ActionEating::isFinished() {
    return time >= maxTime;
}
