//
// Created by TriD on 17.10.2021.
//

#include "actors_needs.h"

#include "../../actions/constants.h"

#include "../../world.h"
#include "../constants.h"

namespace Core::AI::Actors {

int ActorsNeeds::getFood() const { return _food; }

void ActorsNeeds::setFood(int food) { _food = food; }

int ActorsNeeds::getWater() const { return _water; }

void ActorsNeeds::setWater(int water) { _water = water; }

int ActorsNeeds::getMaxFood() const { return _maxFood; }

void ActorsNeeds::setMaxFood(int maxFood) {
    _maxFood = maxFood;
    _food = maxFood;
}

int ActorsNeeds::getMaxWater() const { return _maxWater; }

void ActorsNeeds::setMaxWater(int maxWater) {
    _maxWater = maxWater;
    _water = maxWater;
}

} // namespace Core::AI::Actors