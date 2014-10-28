#include "world.h"

#include "ai/actor.h"
#include "application.h"

#include <iostream>
using namespace std;

void World::moveActor(Actor *actor, const string &dest) {
    TravelPtr route(new Travel(actor, dest));
    inRoute.push_back(route);
}

void World::update(int delta) {
    for (TravelPtr travelPtr: inRoute) {
        travelPtr->update(delta);
    }
    inRoute.remove_if([](TravelPtr ptr){ return ptr->finished(); });
}

void Travel::update(int delta) {
    distancePassed += actor->getSpeed() * delta / 1000;
    actor->updatePosition(dx * delta, dy * delta);
    if (distancePassed >= distanceNeeded) {
        Message message;
        message.messageType = MESSAGE_FINISHED_MOVING;
        actor->setPosition(dest);
        MessageManager::getInstance().dispatchMessage(actor->getID(), message);
    }
}

void WorldProcess::update(int delta) {
    World::getWorld().update(delta);
}

bool WorldProcess::finished() {
    return false;
}

World::World() {
    ProcessPtr ptr(new WorldProcess());
    Application::getInstance().addProcess(ptr);
}
