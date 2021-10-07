#include "action_eating.h"

#include "../world.h"
#include "../ai/constants.h"

#include "constants.h"

namespace Core::Actions {

bool ActionEating::isValid() {
    return actor->getPosition() == kHomeLocationName;
}

void ActionEating::update(int delta) {
    time += delta;
    if (time >= maxTime) {
        time = maxTime;
        actor->setFood(actor->getMaxFood());
        actor->removeGlobalState(kHungryStateName);
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

ActionEating::ActionEating(Actor* actor, Core::World& world) :
        Action(actor, world),
        maxTime(kActionEatTime),
        _world(world) {

}

} // namespace Core::Actions