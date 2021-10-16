#include "registry.h"

#include <sstream>

#include "../constants.h"

Core::AI::Actors::ActorsRegistry* g_actorsRegistry = nullptr;

namespace Core::AI::Actors {

const std::vector<Actor*>& ActorsRegistry::getActors() const {
    return actors;
}

std::vector<Actor*>& ActorsRegistry::getActors() {
    return actors;
}

Actor& ActorsRegistry::createActor(View::ViewFacade& view, Core::World& world, View::Widgets::GUIPanel& guiPanel) {
    Actor* actor = new Actor(nextId, view, world, guiPanel);
    nextId++;
    actors.push_back(actor);
    return *actor;
}

void ActorsRegistry::update() {

}

Actor* ActorsRegistry::getActor(int id) {
    return (actors.empty()) ? (Actor*) nullptr : actors[id];
}

void ActorsRegistry::ActorRegistryProcess::update(int delta) {
    _actorsRegistry.update();
}

bool ActorsRegistry::ActorRegistryProcess::finished() {
    return false;
}

ActorsRegistry::ActorRegistryProcess::ActorRegistryProcess(ActorsRegistry& actorsRegistry) : _actorsRegistry(
        actorsRegistry) {}

ActorsRegistry::ActorsRegistry(Core::Application& application) {
    g_actorsRegistry = this;

    Core::ProcessPtr ptr(new ActorRegistryProcess(*this));
    application.addProcess(ptr);
    application.addProcess(Core::ProcessPtr(new ActorStatusUpdateProcess(*this)));
}

void ActorsRegistry::ActorStatusUpdateProcess::update(int delta) {
    time += delta;
    if (time > interval) {
        time -= interval;
        for (Actor* actor: _actorRegistry.getActors()) {
            updateNeeds(actor);
        }
    }
}

void ActorsRegistry::ActorStatusUpdateProcess::updateNeeds(Actor* actor) const {
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

bool ActorsRegistry::ActorStatusUpdateProcess::finished() {
    return false;
}

ActorsRegistry::ActorStatusUpdateProcess::ActorStatusUpdateProcess(ActorsRegistry& actorRegistry) : _actorRegistry(
        actorRegistry) {}

} // namespace Core::AI::Actors