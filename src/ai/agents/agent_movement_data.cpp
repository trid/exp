//
// Created by TriD on 17.10.2021.
//

#include "agent_movement_data.h"

#include "../../core/constants.h"

namespace Core::AI::Agents {


void AgentPositioningData::updatePosition(double dx, double dy) {
    _x += dx;
    _y += dy;
}

int AgentPositioningData::getX() const { return static_cast<int>(_x); }

void AgentPositioningData::setX(int x) { _x = x; }

int AgentPositioningData::getY() const { return static_cast<int>(_y); }

void AgentPositioningData::setY(int y) { _y = y; }

double AgentPositioningData::getSpeed() const { return _speed; }

void AgentPositioningData::setSpeed(double speed) { _speed = speed; }

} // namespace Core::AI::Agents
