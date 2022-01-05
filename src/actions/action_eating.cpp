#include "action_eating.h"

#include "../ai/constants.h"

#include "../world.h"

#include "constants.h"

namespace Core::Actions {

bool ActionEating::isValid() {
    const auto& location = _world.getAgentsLocation(*actor);
    return location && *location == Core::AI::kHomeLocationName;
}

void ActionEating::update(int delta) {
    _time += delta;
    if (_time >= _maxTime) {
        _time = _maxTime;
        actor->setFood(actor->getMaxFood());
        actor->removeStatus(Core::AI::kHungryStateName);
        _world.removeFood();
        stop();
    }
}

int ActionEating::progress() {
    return _time * 100 / _maxTime;;
}

bool ActionEating::isFinished() {
    return _time >= _maxTime;
}

ActionEating::ActionEating(AI::Actors::Agent* actor, Core::World& world) :
        Action(actor, world),
        _maxTime(kActionEatTime),
        _world(world) {

}

} // namespace Core::Actions