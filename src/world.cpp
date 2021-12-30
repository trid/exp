#include "world.h"

#include <iostream>

#include "application.h"
#include "constants.h"
#include "location_type.h"
#include "travel.h"
#include "world_process.h"

#include "actions/action_manager.h"
#include "actions/constants.h"

#include "ai/actors/agent.h"


namespace Core {

TravelPtr World::moveActor(AI::Actors::Agent* actor, const std::string& dest) {
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


    for (Actions::ActionPtr& actionPtr: actions) {
        actionPtr->update(delta);
    }

    for (Actions::ActionPtr& actionPtr: actions) {
        if (!actionPtr->isValid() || actionPtr->isFinished() || !actionPtr->isRunning()) {
            // TODO: Check what is happening here
            actionPtr->getActor()->removeAction();
        }
    }

    actions.remove_if([](auto& action) {
        return !action->isValid() || action->isFinished() || !action->isRunning();
    });
}

World::World(Application& application, GlobalMessageManager& appMessageManager) :
        _actionManager(*this),
        _actorsRegistry(application),
        _messageManager(_actorsRegistry),
        _globalMessageManager(appMessageManager) {
    ProcessPtr ptr = std::make_shared<WorldProcess>(*this);
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

void World::doAction(AI::Actors::Agent* actor, const std::string& action) {
    const auto& placeActions = getActions(actor);
    if (placeActions.find(action) != placeActions.end()) {
        Actions::ActionPtr actionInstance = _actionManager.getAction(action, actor);
        actor->setAction(actionInstance);
        actions.push_back(actionInstance);
    }
}

void World::removeFood() {
    food--;
    _globalMessageManager.sendMessage(kFoodUpdatedMessage, MessageData());
}

void World::addFood(int i) {
    food += i;
    _globalMessageManager.sendMessage(kFoodUpdatedMessage, MessageData());
}

void World::addWood(int i) {
    wood += i;

    _globalMessageManager.sendMessage(kWoodUpdatedMessage, MessageData());
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

GlobalMessageManager& World::getGlobalMessageManager() {
    return _globalMessageManager;
}

boost::optional<const std::string&> World::getAgentsLocation(const AI::Actors::AgentMovementData& agent) const {
    // TODO: Change for something that works faster than O(n)

    auto isInLocation = [&agent](const auto& locationIter) {
        const auto& location = locationIter.second;
        if (agent.getX() < location->getXPos()) return false;
        if (agent.getY() < location->getYPos()) return false;
        if (agent.getX() > location->getXPos() + location->getType().getWidth()) return false;
        if (agent.getY() > location->getYPos() + location->getType().getHeight()) return false;
        return true;
    };

    const auto& locations = _worldMap.getLocations();
    auto it = std::find_if(locations.begin(), locations.end(), isInLocation);
    if (it != locations.end()) {
        return it->first;
    }

    return boost::none;
}

} // namespace Core