//
// Created by TriD on 17.10.2021.
//

#include "actors_needs.h"

namespace Core::AI::Actors {

int ActorNeeds::getFood() const { return _food; }

void ActorNeeds::setFood(int food) { _food = food; }

int ActorNeeds::getWater() const { return _water; }

void ActorNeeds::setWater(int water) { _water = water; }

int ActorNeeds::getMaxFood() const { return _maxFood; }

void ActorNeeds::setMaxFood(int maxFood) {
    _maxFood = maxFood;
    _food = maxFood;
}

int ActorNeeds::getMaxWater() const { return _maxWater; }

void ActorNeeds::setMaxWater(int maxWater) {
    _maxWater = maxWater;
    _water = maxWater;
}

} // namespace Core::AI::Actors