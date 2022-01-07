//
// Created by TriD on 07.01.2022.
//

#include "agents_updater.h"

#include "../constants.h"

namespace Core::AI::Actors {

AgentNeedsUpdater::AgentNeedsUpdater(AgentsRegistry& actorRegistry) : _actorRegistry(
        actorRegistry) {}

void AgentNeedsUpdater::update(unsigned int delta) {
    _time += delta;
    if (_time > _interval) {
        _time -= _interval;
        for (Agent* actor: _actorRegistry.getActors()) {
            updateNeeds(actor);
        }
    }
}

void AgentNeedsUpdater::updateNeeds(Agent* actor) const {
    int food = actor->getFood();
    if (food > 0) {
        actor->setFood(food - 1);
    } else {
        actor->addStatus(kHungryStateName);
    }

    int water = actor->getWater();
    if (water > 0) {
        actor->setWater(water - 1);
    } else {
        actor->addStatus(kThirstyStateName);
    }
}

bool AgentNeedsUpdater::finished() {
    return false;
}

} // namespace Core::AI::Actors
