#include "action_hunting.h"

#include "../ai/constants.h"
#include "../ai/actors/agent.h"

#include "../core/world.h"

#include "constants.h"

namespace Core::Actions {

bool ActionHunting::isValid() const {
    const auto& location = _world.getAgentsLocation(_actor);
    return location && *location == Core::AI::kForestLocationName;
}

void ActionHunting::update(int delta) {
    _time += delta;
    if (_time >= _interval) {
        _time -= _interval;
        _actor.addItem(kItemFood);
    }
}

int ActionHunting::progress() {
    return 0;
}

bool ActionHunting::isFinished() const {
    return false;
}

ActionHunting::ActionHunting(AI::Actors::Agent& actor, Core::World& world) :
        Action(actor, world),
        _interval(kActionHuntTime),
        _world(world) {}

} // namespace Core::Actions