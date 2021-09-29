#include "world.h"

#include "ai/actor.h"
#include "application.h"
#include "action_manager.h"
#include "location_manager.h"

#include <iostream>
using namespace std;

extern World* g_world;

void World::moveActor(Actor *actor, const string &dest) {
    TravelPtr route(new Travel(actor, dest, _sceneObjectManager, *this));
    actor->setPosition("In route");
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

void WorldProcess::update(int delta) {
    _world.update(delta);
}

bool WorldProcess::finished() {
    return false;
}

WorldProcess::WorldProcess(World& world):
    _world(world)
{

}

World::World(View& view, Application& application) :
        _sceneObjectManager(view),
        _actionManager(*this),
        _actorsRegistry(application),
        _messageManager(_actorsRegistry)
{
    g_world = this;
    ProcessPtr ptr(new WorldProcess(*this));
    application.addProcess(ptr);

    homeActions.emplace("eat");
    homeActions.emplace("rest");
    forestActions.emplace("hunt");
    forestActions.emplace("cut_wood");
    wellActions.emplace("drink");
}

unordered_set<string> const & World::getActions(Actor *actor) {
    Location* location = LocationManager::getInstance().getLocation(actor->getPosition());
    return location->getType()->getActions();
}

void World::doAction(Actor *actor, const string &action) {
    unordered_set<string> const &placeActions = getActions(actor);
    if (placeActions.find(action) != placeActions.end()) {
        ActionPtr actionInstance = _actionManager.getAction(action, actor);
        actor->setAction(actionInstance);
        actions.push_back(actionInstance);
    }
}

void World::removeFood() {
    food--;
    UIMessageManager::getInstance().sendMessage("FOOD_UPDATED_MESSAGE", UIMessageData());
}

void World::addFood(int i) {
    food += i;
    UIMessageManager::getInstance().sendMessage("FOOD_UPDATED_MESSAGE", UIMessageData());
}

void World::addWood(int i) {
    wood += i;

    UIMessageManager::getInstance().sendMessage("WOOD_UPDATED_MESSAGE", UIMessageData());
}

SceneObjectManager& World::getSceneObjectManager() {
    return _sceneObjectManager;
}

MessageManager& World::getMessageManager() {
    return _messageManager;
}

int World::getFood() const {
    return food;
}


void Travel::update(int delta) {
    distancePassed += actor->getSpeed() * delta / 1000;
    actor->updatePosition(dx * delta, dy * delta);
    if (distancePassed >= distanceNeeded) {
        Message message;
        message.messageType = MESSAGE_FINISHED_MOVING;
        actor->setPosition(dest);
        world.getMessageManager().dispatchMessage(actor->getID(), message);
    }
}