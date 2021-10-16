//
// Created by TriD on 17.10.2021.
//

#include "actor_movement_data.h"

#include "../../constants.h"
#include "../../world.h"

namespace Core::AI::Actors {

const std::string& ActorMovementData::getPosition() const { return _position; }

void ActorMovementData::setPosition(World& world, const std::string& position) {
    _position = position;
    if (position != Core::kPositionInRoute) {
        const auto mapObject = world.getWorldMap().getLocation(position);
        _x = mapObject->getXPos();
        _y = mapObject->getYPos();
    }
}

void ActorMovementData::setTargetPosition(const std::string& position) {
    _target = position;
}

const std::string& ActorMovementData::getTargetPosition() {
    return _target;
}

void ActorMovementData::updatePosition(double dx, double dy) {
    _x += dx;
    _y += dy;
}

int ActorMovementData::getX() const { return static_cast<int>(_x); }

void ActorMovementData::setX(int x) { _x = x; }

int ActorMovementData::getY() const { return static_cast<int>(_y); }

void ActorMovementData::setY(int y) { _y = y; }

double ActorMovementData::getSpeed() const { return _speed; }

void ActorMovementData::setSpeed(double speed) { _speed = speed; }

} // namespace Core::AI::Actors
