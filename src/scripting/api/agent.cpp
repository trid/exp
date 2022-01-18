//
// Created by TriD on 31.12.2021.
//

#include "agent.h"

#include "../../core/world.h"

namespace Scripting::API {

Agent::Agent(Core::World& world, int id) : _world(world), _id(id) {}

void Agent::say(const std::string& message) {
    _world.getAgentsRegistry().getActors()[_id].say(message);
}

int Agent::getWater() const {
    return _world.getAgentsRegistry().getActors()[_id].getWater();
}

int Agent::getFood() const {
    return _world.getAgentsRegistry().getActors()[_id].getFood();
}

boost::optional<const std::string&> Agent::getPosition() const {
    const auto& actor = _world.getAgentsRegistry().getActors()[_id];
    return _world.getAgentLocator().getAgentsLocation(actor);
}

int Agent::getInventory() const {
    return _world.getAgentsRegistry().getActors()[_id].getAllItemsCount();
}

int Agent::getInventoryLimit() const {
    return _world.getAgentsRegistry().getActors()[_id].getInventoryLimit();
}

void Agent::unloadResource(const std::string& resource) {
    auto& agent = _world.getAgentsRegistry().getActors()[_id];
    _world.getInventory().unloadResource(agent, resource);
}

bool Agent::hasAction() const {
    return _world.getAgentsRegistry().getActors()[_id].hasAction();
}

void Agent::addStatus(const std::string& status) {
    _world.getAgentsRegistry().getActors()[_id].addStatus(status);
}

Core::TravelPtr Agent::move(const std::string& dest) {
    return _world.getMovementUpdater().moveActor(_world.getAgentsRegistry().getActors()[_id], dest);
}

void Agent::doAction(const std::string& action) {
    _world.doAction(_world.getAgentsRegistry().getActors()[_id], action);
}

void Agent::clearState() {
    _world.getAgentsRegistry().getActors()[_id].setBehaviourStep(boost::none);
}

}