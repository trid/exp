#include "action_woodcutting.h"

#include "../ai/constants.h"

#include "../world.h"

#include "constants.h"

namespace Core::Actions {

bool ActionWoodcutting::isValid() {
    const auto& location = _world.getAgentsLocation(*actor);
    return location && *location == Core::AI::kForestLocationName;
}

void ActionWoodcutting::update(int delta) {
    _time += delta;
    if (_time >= _interval) {
        _time -= _interval;
        actor->addItem(kItemWood);
    }
}

int ActionWoodcutting::progress() {
    return 0;
}

bool ActionWoodcutting::isFinished() {
    return false;
}

ActionWoodcutting::ActionWoodcutting(AI::Actors::Agent* actor, Core::World& world) :
        Action(actor, world),
        _interval(kWoodcuttingTime),
        _world(world) {}

} // namespace Core::Actions