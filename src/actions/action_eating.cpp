#include "action_eating.h"
#include "../world.h"

bool ActionEating::isValid() {
    return actor->getPosition() == "home";
}

void ActionEating::update(int delta) {
    time += delta;
    if (time >= maxTime) {
        time = maxTime;
        actor->setFood(actor->getMaxFood());
        actor->removeGlobalState("hungry");
        _world.removeFood();
        stop();
    }
}

int ActionEating::progress() {
    return time * 100 / maxTime;;
}

bool ActionEating::isFinished() {
    return time >= maxTime;
}

ActionEating::ActionEating(Actor* actor, World& world):
        Action(actor, world),
        _world(world)
{

}
