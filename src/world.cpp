#include "world.h"

#include "actor.h"

#include <iostream>
using namespace std;

void World::moveActor(Actor *actor, const string &dest, int distance) {
    TravelPtr route(new Travel(actor, dest, distance));
    inRoute.push_back(route);
}

void World::update() {
    for (TravelPtr travelPtr: inRoute) {
        travelPtr->update();
    }
    inRoute.remove_if([](TravelPtr ptr){ return ptr->finished(); });
}

void Travel::update() {
    distancePassed++;
    if (distancePassed >= distanceNeeded) {
        Message message;
        message.messageType = MESSAGE_FINISHED_MOVING;
        actor->setPosition(dest);
        MessageManager::getInstance().dispatchMessage(actor->getID(), message);
    }
}
