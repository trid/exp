//
// Created by TriD on 01.11.2021.
//

#include "travel.h"

#include "agent_locator.h"
#include "constants.h"
#include "message_manager.h"
#include "world.h"

#include "ai/actors/agent.h"

namespace Core {

void Travel::update(int delta) {
    distancePassed += actor->getSpeed() * delta / 1000;
    actor->updatePosition(dx * delta, dy * delta);
    if (distancePassed >= distanceNeeded) {
        Message message;
        message.messageType = kFinishedMovingMessage;
        _agentLocator.setAgentLocation(*actor, dest);
        _messageBus.dispatchMessage(actor->getID(), message);
    }
}

Travel::Travel(AI::Actors::Agent* actor, const std::string& dest, const WorldMap& worldMap, const AgentLocator& locator,
               MessageManager& messageBus)
        : actor(actor), dest(dest),
          distancePassed(0), _agentLocator(locator),
          _messageBus(messageBus) {
    const auto location = worldMap.getLocation(dest);
    int xDist = location->getXPos() - actor->getX();
    int yDist = location->getYPos() - actor->getY();
    double angle = atan2(yDist, xDist);
    dx = cos(angle) * actor->getSpeed() / 1000;
    dy = sin(angle) * actor->getSpeed() / 1000;
    distanceNeeded = (int) sqrt(xDist * xDist + yDist * yDist);
}

} // namespace Core