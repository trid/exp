#include "registry.h"

#include "actor.h"
#include "application.h"

const vector<Actor *> &ActorsRegistry::getActors() {
    return actors;
}

Actor &ActorsRegistry::createActor() {
    Actor* actor = new Actor();
    actor->id = nextId;
    nextId++;
    actors.push_back(actor);
    return *actor;
}

void ActorsRegistry::update() {
    for (Actor* actor: actors) {
        actor->update();
    }
}

Actor *ActorsRegistry::getActor(int id) {
    return (actors.empty()) ? nullptr : actors[id];
}

void ActorsRegistry::ActorRegistryProcess::update(int delta) {
    ActorsRegistry::getRegistry().update();
}

bool ActorsRegistry::ActorRegistryProcess::finished() {
    return false;
}

ActorsRegistry::ActorsRegistry() {
    ProcessPtr ptr(new ActorRegistryProcess());
    Application::getInstance().addProcess(ptr);
}
