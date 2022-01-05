#include "action_drink.h"

#include "../ai/constants.h"
#include "../ai/actors/agent.h"

#include "../world.h"

#include "constants.h"

namespace Core::Actions {

bool ActionDrink::isValid() {
    const auto& location = _world.getAgentsLocation(*actor);
    return location && *location == kWellLocationName;
}

void ActionDrink::update(int delta) {
    _time += delta;
    if (_time >= _maxTime) {
        _time = _maxTime;
        actor->setWater(actor->getMaxWater());
        actor->removeStatus(Core::AI::kThirstyStateName);
        actor->say(kActionDrinkExecutedMessage);
    }
}

int ActionDrink::progress() {
    return _time * 100 / _maxTime;
}

bool ActionDrink::isFinished() {
    return _time >= _maxTime;
}

ActionDrink::ActionDrink(AI::Actors::Agent* actor, Core::World& world) :
        Action(actor, world),
        _maxTime(kActionDrinkTime),
        _world(world) {}

} // namespace Core::Actions