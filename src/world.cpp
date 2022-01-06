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

void World::update(int delta) {
    MovementUpdater::update(delta);

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

World::World(Application& application, GlobalMessageManager& appMessageManager, WorldMap& worldMap) :
        WorldInventory(appMessageManager),
        AgentLocator(worldMap),
        MovementUpdater(worldMap, *this, _messageManager),
        _actionManager(*this),
        _actorsRegistry(application),
        _messageManager(_actorsRegistry),
        _globalMessageManager(appMessageManager),
        _worldMap(worldMap) {
    ProcessPtr ptr = std::make_shared<WorldProcess>(*this);
    application.addProcess(ptr);
}

std::unordered_set<std::string> const& World::getActions(AI::Actors::Agent* actor) {
    const auto locationName = getAgentsLocation(*actor);
    if (locationName) {
        const auto location = _worldMap.getLocation(*locationName);
        return location->getType().getActions();
    }
    return _worldMap.getLocation(kPositionInRoute)->getType().getActions();
}

void World::doAction(AI::Actors::Agent* actor, const std::string& action) {
    const auto& placeActions = getActions(actor);
    if (placeActions.find(action) != placeActions.end()) {
        Actions::ActionPtr actionInstance = _actionManager.getAction(action, actor);
        actor->setAction(actionInstance);
        actions.push_back(actionInstance);
    }
}

MessageManager& World::getMessageManager() {
    return _messageManager;
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

} // namespace Core