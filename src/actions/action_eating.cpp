#include "action_eating.h"

#include "../ai/constants.h"

#include "../core/world.h"

#include "constants.h"

namespace Core::Actions {

bool ActionEating::isValid() const {
    const auto& location = _world.getAgentLocator().getAgentsLocation(_actor);
    return location && *location == Core::AI::kHomeLocationName;
}

void ActionEating::update(int delta) {
    _time += delta;
    if (_time >= _maxTime) {
        _time = _maxTime;
        _actor.setFood(_actor.getMaxFood());
        _actor.removeStatus(Core::AI::kHungryStateName);
        _world.getInventory().removeResource(kItemFood, 1);
        stop();
    }
}

int ActionEating::progress() {
    return _time * 100 / _maxTime;;
}

bool ActionEating::isFinished() const {
    return _time >= _maxTime;
}

ActionEating::ActionEating(AI::Agents::Agent& actor, Core::World& world) :
        Action(actor, world),
        _maxTime(kActionEatTime),
        _world(world) {

}

} // namespace Core::Actions