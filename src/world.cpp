#include "world.h"

#include <iostream>

#include "application.h"
#include "constants.h"
#include "location_type.h"

#include "actions/action_manager.h"
#include "actions/constants.h"

#include "ai/actors/agent.h"


namespace Core {

TravelPtr World::moveActor(AI::Actors::Agent* actor, const string& dest) {
    auto route = std::make_shared<Travel>(actor, dest, _worldMap, *this);
    actor->setPosition(*this, kPositionInRoute);
    inRoute.push_back(route);
    return route;
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

World::World(Application& application, GlobalMessageManager& appMessageManager) :
        _actionManager(*this),
        _actorsRegistry(application),
        _messageManager(_actorsRegistry),
        _appMessageManager(appMessageManager) {
    ProcessPtr ptr(new WorldProcess(*this));
    application.addProcess(ptr);

    homeActions.emplace(Actions::kActionEat);
    homeActions.emplace(Actions::kActionRest);
    forestActions.emplace(Actions::kActionHunt);
    forestActions.emplace(Actions::kActionCutWood);
    wellActions.emplace(Actions::kActionDrink);
}

std::unordered_set<std::string> const& World::getActions(AI::Actors::Agent* actor) {
    const auto location = _worldMap.getLocation(actor->getPosition());
    return location->getType().getActions();
}

void World::doAction(AI::Actors::Agent* actor, const string& action) {
    const auto& placeActions = getActions(actor);
    if (placeActions.find(action) != placeActions.end()) {
        Actions::ActionPtr actionInstance = _actionManager.getAction(action, actor);
        actor->setAction(actionInstance);
        actions.push_back(actionInstance);
    }
}

void World::removeFood() {
    food--;
    _appMessageManager.sendMessage(kFoodUpdatedMessage, MessageData());
}

void World::addFood(int i) {
    food += i;
    _appMessageManager.sendMessage(kFoodUpdatedMessage, MessageData());
}

void World::addWood(int i) {
    wood += i;

    _appMessageManager.sendMessage(kWoodUpdatedMessage, MessageData());
}

MessageManager& World::getMessageManager() {
    return _messageManager;
}

int World::getFood() const {
    return food;
}

AI::Actors::AgentsRegistry& World::getAgentsRegistry() {
    return _actorsRegistry;
}

const AI::Actors::AgentsRegistry& World::getAgentsRegistry() const {
    return _actorsRegistry;
}

const WorldMap& World::getWorldMap() const {
    return _worldMap;
}

WorldMap& World::getWorldMap() {
    return _worldMap;
}

const LocationTypeManager& World::getLocationTypeManager() const {
    return _locationTypeManager;
}


void Travel::update(int delta) {
    distancePassed += actor->getSpeed() * delta / 1000;
    actor->updatePosition(dx * delta, dy * delta);
    if (distancePassed >= distanceNeeded) {
        Message message;
        message.messageType = kFinishedMovingMessage;
        actor->setPosition(world, dest);
        world.getMessageManager().dispatchMessage(actor->getID(), message);
    }
}

Travel::Travel(AI::Actors::Agent* actor, const string& dest, const WorldMap& worldMap, World& world)
        : actor(actor), dest(dest),
          distancePassed(0), world(world) {
    const auto location = worldMap.getLocation(dest);
    int xDist = location->getXPos() - actor->getX();
    int yDist = location->getYPos() - actor->getY();
    double angle = atan2(yDist, xDist);
    dx = cos(angle) * actor->getSpeed() / 1000;
    dy = sin(angle) * actor->getSpeed() / 1000;
    distanceNeeded = (int) sqrt(xDist * xDist + yDist * yDist);
}

} // namespace Core