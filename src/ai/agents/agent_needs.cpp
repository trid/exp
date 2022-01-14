//
// Created by TriD on 17.10.2021.
//

#include "agent_needs.h"

namespace Core::AI::Agents {

int AgentNeeds::getFood() const { return _food; }

void AgentNeeds::setFood(int food) { _food = food; }

int AgentNeeds::getWater() const { return _water; }

void AgentNeeds::setWater(int water) { _water = water; }

int AgentNeeds::getMaxFood() const { return _maxFood; }

void AgentNeeds::setMaxFood(int maxFood) {
    _maxFood = maxFood;
    _food = maxFood;
}

int AgentNeeds::getMaxWater() const { return _maxWater; }

void AgentNeeds::setMaxWater(int maxWater) {
    _maxWater = maxWater;
    _water = maxWater;
}

} // namespace Core::AI::Agents