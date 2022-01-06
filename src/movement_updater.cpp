//
// Created by TriD on 06.01.2022.
//

#include "movement_updater.h"

#include <algorithm>

#include "travel.h"

namespace Core {

MovementUpdater::MovementUpdater(const WorldMap& worldMap, const AgentLocator& locator,
                                 MessageManager& messageBus) :
                                 _worldMap(worldMap),
                                 _agentLocator(locator),
                                 _messageBus(messageBus) {}

TravelPtr MovementUpdater::moveActor(AI::Actors::Agent* actor, const std::string& dest) {
    auto route = std::make_shared<Travel>(actor, dest, _worldMap, _agentLocator, _messageBus);
    _inRoute.push_back(route);
    return route;
}

void MovementUpdater::update(int delta) {
    for (TravelPtr travelPtr: _inRoute) {
        travelPtr->update(delta);
    }

    auto iter = std::remove_if(_inRoute.begin(), _inRoute.end(), [](TravelPtr ptr) { return ptr->finished(); });
    _inRoute.erase(iter, _inRoute.end());
}

} // namespace Core