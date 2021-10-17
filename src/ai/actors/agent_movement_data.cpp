//
// Created by TriD on 17.10.2021.
//

#include "agent_movement_data.h"

#include "../../constants.h"
#include "../../world.h"

namespace Core::AI::Actors {

const std::string& AgentMovementData::getPosition() const { return _position; }

void AgentMovementData::setPosition(World& world, const std::string& position) {
    _position = position;
    if (position != Core::kPositionInRoute) {
        const auto mapObject = world.getWorldMap().getLocation(position);
        _x = mapObject->getXPos();
        _y = mapObject->getYPos();
    }
}

void AgentMovementData::setTargetPosition(const std::string& position) {
    _target = position;
}

const std::string& AgentMovementData::getTargetPosition() {
    return _target;
}

void AgentMovementData::updatePosition(double dx, double dy) {
    _x += dx;
    _y += dy;
}

int AgentMovementData::getX() const { return static_cast<int>(_x); }

void AgentMovementData::setX(int x) { _x = x; }

int AgentMovementData::getY() const { return static_cast<int>(_y); }

void AgentMovementData::setY(int y) { _y = y; }

double AgentMovementData::getSpeed() const { return _speed; }

void AgentMovementData::setSpeed(double speed) { _speed = speed; }

} // namespace Core::AI::Actors
