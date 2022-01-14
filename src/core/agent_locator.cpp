//
// Created by TriD on 06.01.2022.
//

#include "agent_locator.h"

#include "../ai/actors/agent.h"

#include "../utils/rect_utils.h"

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
        const auto& locationType = location->getType();
        return Utils::isInRect(agent.getX(), agent.getY(), Utils::Rect<int>{location->getXPos(), location->getYPos(),
                                                                            locationType.getWidth(),
                                                                            locationType.getHeight()});
    };

    const auto& locations = _worldMap.getLocations();
    auto it = std::find_if(locations.begin(), locations.end(), isInLocation);
    if (it != locations.end()) {
        return it->first;
    }

    return boost::none;
}

}