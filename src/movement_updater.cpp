//
// Created by TriD on 06.01.2022.
//

#include "movement_updater.h"

#include <algorithm>

#include "ai/actors/agent.h"

#include "travel.h"

namespace Core {

MovementUpdater::MovementUpdater(const WorldMap& worldMap, const AgentLocator& locator,
                                 MessageManager& messageBus) :
                                 _worldMap(worldMap),
                                 _agentLocator(locator),
                                 _messageBus(messageBus) {}

TravelPtr MovementUpdater::moveActor(AI::Actors::Agent* actor, const std::string& dest) {
    auto route = std::make_shared<Travel>(*actor, dest, _worldMap, _agentLocator, _messageBus);
    _inRoute[actor->getID()] = route;
    return route;
}

void MovementUpdater::update(int delta) {
    for (auto& iter: _inRoute) {
        iter.second->update(delta);
    }

    std::erase_if(_inRoute, [](const auto& iter) { return iter.second->finished(); });
}

} // namespace Core