//
// Created by TriD on 01.11.2021.
//

#include "travel.h"

#include "agent_locator.h"
#include "constants.h"
#include "location_type.h"
#include "message_manager.h"
#include "world.h"

#include "ai/actors/agent.h"

namespace Core {

namespace {

// TODO create utilities and move the function here
std::pair<double, double> normalize(double x, double y) {
    double vecLength = sqrt(x * x + y * y);
    return std::make_pair(x / vecLength, y / vecLength);
}

}

Travel::Travel(AI::Actors::Agent& agent, const std::string& dest, const WorldMap& worldMap,
               const AgentLocator& locator, MessageManager& messageBus)
        : _agent(agent),
          _dest(dest),
          _agentLocator(locator),
          _messageBus(messageBus) {
    const auto location = worldMap.getLocation(dest);
    const auto& locationType = location->getType();

    auto targetX = location->getXPos() + locationType.getWidth() / 2;
    auto targetY = location->getYPos() + locationType.getHeight() / 2;
    int xDist = targetX - _agent.getX();
    int yDist = targetY - _agent.getY();

    auto [normX, normY] = normalize(xDist, yDist);
    _dx = normX * _agent.getSpeed() / 1000;
    _dy = normY * _agent.getSpeed() / 1000;
}

void Travel::update(int delta) {
    _agent.updatePosition(_dx * delta, _dy * delta);

    const auto location = _agentLocator.getAgentsLocation(_agent);
    if (location && *location == _dest) {
        Message message;
        message.messageType = kFinishedMovingMessage;
        _messageBus.dispatchMessage(_agent.getID(), message);
    }
}

bool Travel::finished() const {
    const auto location = _agentLocator.getAgentsLocation(_agent);
    return location && *location == _dest;
}

} // namespace Core