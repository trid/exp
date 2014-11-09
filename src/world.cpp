#include "world.h"

#include "ai/actor.h"
#include "application.h"
#include "action_manager.h"

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
    for (ActionPtr actionPtr: actions) {
        if (actionPtr->isValid() && !actionPtr->isFinished() && actionPtr->isRunning()) {
            actionPtr->update(delta);
        }
    }
    for (ActionPtr actionPtr: actions) {
        if (!actionPtr->isValid() || actionPtr->isFinished() || !actionPtr->isRunning()) {
            actionPtr->getActor()->removeAction();
        }
    }
    actions.remove_if([](ActionPtr ptr){ return ptr->isFinished() || !ptr->isRunning() || !ptr->isValid(); });
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

    homeActions.emplace("eat");
    homeActions.emplace("rest");
    forestActions.emplace("hunt");
    forestActions.emplace("cut_wood");
    wellActions.emplace("drink");
}

const set<string> &World::getActions(Actor *actor) {
    if (actor->getPosition() == "home") {
        return homeActions;
    }
    if (actor->getPosition() == "forest") {
        return forestActions;
    }
    if (actor->getPosition() == "well") {
        return wellActions;
    }
}

void World::doAction(Actor *actor, const string &action) {
    set<string> const &placeActions = getActions(actor);
    if (placeActions.find(action) != placeActions.end()) {
        ActionPtr actionInstance = ActionManager::getInstance().getAction(action, actor);
        actor->setAction(actionInstance);
        actions.push_back(actionInstance);
    }
}
