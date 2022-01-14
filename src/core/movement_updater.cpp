//
// Created by TriD on 06.01.2022.
//

#include "movement_updater.h"

#include "../ai/agents/agent.h"

#include "travel.h"

namespace Core {

MovementUpdater::MovementUpdater(const WorldMap& worldMap, const AgentLocator& locator) :
                                 _worldMap(worldMap),
                                 _agentLocator(locator) {}

TravelPtr MovementUpdater::moveActor(AI::Agents::Agent& actor, const std::string& dest) {
    auto route = std::make_shared<Travel>(actor, dest, _worldMap, _agentLocator);
    _inRoute[actor.getID()] = route;
    return route;
}

void MovementUpdater::update(int delta) {
    for (auto& iter: _inRoute) {
        iter.second->update(delta);
    }

    std::erase_if(_inRoute, [](const auto& iter) { return iter.second->finished(); });
}

} // namespace Core