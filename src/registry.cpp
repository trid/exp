#include "registry.h"

#include "actor.h"

const vector<Actor *> &ActorsRegistry::getActors() {
    return actors;
}

Actor &ActorsRegistry::createActor() {
    Actor* actor = new Actor();
    actors.push_back(actor);
    return *actor;
}
