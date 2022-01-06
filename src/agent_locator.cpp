//
// Created by TriD on 06.01.2022.
//

#include "agent_locator.h"

#include "ai/actors/agent.h"

#include "location_type.h"
#include "world_map.h"

namespace Core {

AgentLocator::AgentLocator(const WorldMap& worldMap) : _worldMap(worldMap) {}

void AgentLocator::setAgentLocation(AI::Actors::Agent& agent, const std::string& position) const {
    const auto mapObject = _worldMap.getLocation(position);
    if (mapObject) {
        agent.setX(mapObject->getXPos());
        agent.setY(mapObject->getYPos());
    }
}

boost::optional<const std::string&>
AgentLocator::getAgentsLocation(const AI::Actors::AgentPositioningData& agent) const {
    // TODO: Change for something that works faster than O(n)

    auto isInLocation = [&agent](const auto& locationIter) {
        const auto& location = locationIter.second;
        if (agent.getX() < location->getXPos()) return false;
        if (agent.getY() < location->getYPos()) return false;
        if (agent.getX() > location->getXPos() + location->getType().getWidth()) return false;
        if (agent.getY() > location->getYPos() + location->getType().getHeight()) return false;
        return true;
    };

    const auto& locations = _worldMap.getLocations();
    auto it = std::find_if(locations.begin(), locations.end(), isInLocation);
    if (it != locations.end()) {
        return it->first;
    }

    return boost::none;
}

}