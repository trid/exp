#include "registry.h"

#include <sstream>

#include "../constants.h"

Core::AI::Actors::AgentsRegistry* g_actorsRegistry = nullptr;

namespace Core::AI::Actors {

const std::vector<Agent*>& AgentsRegistry::getActors() const {
    return actors;
}

std::vector<Agent*>& AgentsRegistry::getActors() {
    return actors;
}

Agent& AgentsRegistry::createAgent(Core::World& world) {
    Agent* actor = new Agent(nextId, world);
    nextId++;
    actors.push_back(actor);
    return *actor;
}

void AgentsRegistry::update() {

}

boost::optional<Agent&> AgentsRegistry::getAgent(int id) {
    return (actors.size() > id) ? boost::optional<Agent&>(*actors[id]) : boost::none;
}

boost::optional<const Agent&> AgentsRegistry::getAgent(int id) const {
    return (actors.size() > id) ? boost::optional<const Agent&>(*actors[id]) : boost::none;
}

void AgentsRegistry::ActorRegistryProcess::update(int delta) {
    _actorsRegistry.update();
}

bool AgentsRegistry::ActorRegistryProcess::finished() {
    return false;
}

AgentsRegistry::ActorRegistryProcess::ActorRegistryProcess(AgentsRegistry& actorsRegistry) : _actorsRegistry(
        actorsRegistry) {}

AgentsRegistry::AgentsRegistry(Core::Application& application) {
    g_actorsRegistry = this;

    Core::ProcessPtr ptr(new ActorRegistryProcess(*this));
    application.addProcess(ptr);
    application.addProcess(Core::ProcessPtr(new ActorStatusUpdateProcess(*this)));
}

int AgentsRegistry::getLastId() const { return actors.back()->getID(); }

void AgentsRegistry::ActorStatusUpdateProcess::update(int delta) {
    time += delta;
    if (time > interval) {
        time -= interval;
        for (Agent* actor: _actorRegistry.getActors()) {
            updateNeeds(actor);
        }
    }
}

void AgentsRegistry::ActorStatusUpdateProcess::updateNeeds(Agent* actor) const {
    int food = actor->getFood();
    if (food > 0) {
        actor->setFood(food - 1);
    } else {
        actor->addStatus(kHungryStateName);
    }

    int water = actor->getWater();
    if (water > 0) {
        actor->setWater(water - 1);
    } else {
        actor->addStatus(kThirstyStateName);
    }
}

bool AgentsRegistry::ActorStatusUpdateProcess::finished() {
    return false;
}

AgentsRegistry::ActorStatusUpdateProcess::ActorStatusUpdateProcess(AgentsRegistry& actorRegistry) : _actorRegistry(
        actorRegistry) {}

} // namespace Core::AI::Actors