//
// Created by TriD on 31.12.2021.
//

#include "agent.h"

#include "../../world.h"

namespace Scripting::API {

Agent::Agent(Core::World& world, int id) : _world(world), _id(id) {}

void Agent::say(const std::string& message) {
    _world.getAgentsRegistry().getActors()[_id]->say(message);
}

int Agent::getWater() {
    return _world.getAgentsRegistry().getActors()[_id]->getWater();
}

int Agent::getFood() {
    return _world.getAgentsRegistry().getActors()[_id]->getFood();
}

const std::string& Agent::getPosition() {
    return _world.getAgentsRegistry().getActors()[_id]->getPosition();
}

int Agent::getInventory() {
    return _world.getAgentsRegistry().getActors()[_id]->getAllItemsCount();
}

int Agent::getInventoryLimit() {
    return _world.getAgentsRegistry().getActors()[_id]->getInventoryLimit();
}

void Agent::unloadWood() {
    return _world.getAgentsRegistry().getActors()[_id]->unloadWood();
}

void Agent::unloadFood() {
    return _world.getAgentsRegistry().getActors()[_id]->unloadFood();
}

bool Agent::hasAction() {
    return _world.getAgentsRegistry().getActors()[_id]->hasAction();
}

void Agent::addStatus(const std::string& status) {
    _world.getAgentsRegistry().getActors()[_id]->addStatus(status);
}

Core::TravelPtr Agent::move(const std::string& dest) {
    return _world.moveActor(_world.getAgentsRegistry().getActors()[_id], dest);
}

void Agent::doAction(const std::string& action) {
    _world.doAction(_world.getAgentsRegistry().getActors()[_id], action);
}

void Agent::clearState() {
    _world.getAgentsRegistry().getActors()[_id]->setBehaviourStep(boost::none);
}

}