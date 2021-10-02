#include "registry.h"

#include <sstream>

#include "../scripting/script_object_manager.h"

#include "actor_object.h"
#include "constants.h"

using std::stringstream;

extern ActorsRegistry* g_actorsRegistry;

const vector<Actor *> &ActorsRegistry::getActors() {
    return actors;
}

Actor& ActorsRegistry::createActor(View& view, World& world, GUIPanel& guiPanel) {
    Actor* actor = new Actor(view, world, guiPanel);
    actor->id = nextId;
    nextId++;
    actors.push_back(actor);
    ActorObject* actorObject = new ActorObject(actor);
    stringstream ss;
    ss << kTemporaryActorNamePrefix << actor->getID();
    ScriptObjectManager::getInstance().addItem(ss.str(), actorObject);
    return *actor;
}

void ActorsRegistry::update() {
    for (Actor* actor: actors) {
        actor->update();
    }
}

Actor *ActorsRegistry::getActor(int id) {
    return (actors.empty()) ? (Actor*)nullptr : actors[id];
}

void ActorsRegistry::ActorRegistryProcess::update(int delta) {
    _actorsRegistry.update();
}

bool ActorsRegistry::ActorRegistryProcess::finished() {
    return false;
}

ActorsRegistry::ActorRegistryProcess::ActorRegistryProcess(ActorsRegistry& actorsRegistry) : _actorsRegistry(
        actorsRegistry) {}

ActorsRegistry::ActorsRegistry(Application& application) {
    g_actorsRegistry = this;

    ProcessPtr ptr(new ActorRegistryProcess(*this));
    application.addProcess(ptr);
    application.addProcess(ProcessPtr(new ActorStatusUpdateProcess(*this)));
}

void ActorsRegistry::ActorStatusUpdateProcess::update(int delta) {
    time += delta;
    if (time > interval) {
        time -= interval;
        for (Actor* actor: _actorRegistry.getActors()) {
            actor->updateStatus();
        }
    }
}

bool ActorsRegistry::ActorStatusUpdateProcess::finished() {
    return false;
}

ActorsRegistry::ActorStatusUpdateProcess::ActorStatusUpdateProcess(ActorsRegistry& actorRegistry) : _actorRegistry(
        actorRegistry) {}
