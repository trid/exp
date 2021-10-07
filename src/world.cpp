#include "world.h"

#include <iostream>

#include "application.h"
#include "constants.h"
#include "location_manager.h"
#include "location_type.h"

#include "actions/action_manager.h"
#include "actions/constants.h"

#include "ai/actor.h"

#include "view/view_facade.h"

Core::World* g_world;

namespace Core {

void World::moveActor(AI::Actor* actor, const string& dest) {
    auto route = std::make_shared<Travel>(actor, dest, _sceneObjectManager, *this);
    actor->setPosition(kPositionInRoute);
    inRoute.push_back(route);
}

void World::update(int delta) {
    for (TravelPtr travelPtr: inRoute) {
        travelPtr->update(delta);
    }
    inRoute.remove_if([](TravelPtr ptr) { return ptr->finished(); });
    for (Actions::ActionPtr actionPtr: actions) {
        if (actionPtr->isValid() && !actionPtr->isFinished() && actionPtr->isRunning()) {
            actionPtr->update(delta);
        }
    }
    for (Actions::ActionPtr actionPtr: actions) {
        if (!actionPtr->isValid() || actionPtr->isFinished() || !actionPtr->isRunning()) {
            actionPtr->getActor()->removeAction();
        }
    }
    actions.remove_if([](Actions::ActionPtr ptr) { return ptr->isFinished() || !ptr->isRunning() || !ptr->isValid(); });
}

void WorldProcess::update(int delta) {
    _world.update(delta);
}

bool WorldProcess::finished() {
    return false;
}

WorldProcess::WorldProcess(World& world) :
        _world(world) {

}

World::World(View::ViewFacade& view, Application& application) :
        _view(view),
        _sceneObjectManager(view),
        _actionManager(*this),
        _actorsRegistry(application),
        _messageManager(_actorsRegistry),
        _locationManager(_locationTypeManager) {
    g_world = this;
    ProcessPtr ptr(new WorldProcess(*this));
    application.addProcess(ptr);

    homeActions.emplace(Actions::kActionEat);
    homeActions.emplace(Actions::kActionRest);
    forestActions.emplace(Actions::kActionHunt);
    forestActions.emplace(Actions::kActionCutWood);
    wellActions.emplace(Actions::kActionDrink);
}

std::unordered_set<std::string> const& World::getActions(AI::Actor* actor) {
    Location* location = _locationManager.getLocation(actor->getPosition());
    return location->getType()->getActions();
}

void World::doAction(AI::Actor* actor, const string& action) {
    const auto& placeActions = getActions(actor);
    if (placeActions.find(action) != placeActions.end()) {
        Actions::ActionPtr actionInstance = _actionManager.getAction(action, actor);
        actor->setAction(actionInstance);
        actions.push_back(actionInstance);
    }
}

void World::removeFood() {
    food--;
    _view.getUIMessageManager().sendMessage(kFoodUpdatedMessage, UIMessageData());
}

void World::addFood(int i) {
    food += i;
    _view.getUIMessageManager().sendMessage(kFoodUpdatedMessage, UIMessageData());
}

void World::addWood(int i) {
    wood += i;

    _view.getUIMessageManager().sendMessage(kWoodUpdatedMessage, UIMessageData());
}

View::SceneObjectManager& World::getSceneObjectManager() {
    return _sceneObjectManager;
}

MessageManager& World::getMessageManager() {
    return _messageManager;
}

int World::getFood() const {
    return food;
}

LocationManager& World::getLocationManager() {
    return _locationManager;
}


void Travel::update(int delta) {
    distancePassed += actor->getSpeed() * delta / 1000;
    actor->updatePosition(dx * delta, dy * delta);
    if (distancePassed >= distanceNeeded) {
        Message message;
        message.messageType = kFinishedMovingMessage;
        actor->setPosition(dest);
        world.getMessageManager().dispatchMessage(actor->getID(), message);
    }
}

} // namespace Core