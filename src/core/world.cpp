#include "world.h"

#include <iostream>

#include "constants.h"
#include "location_type.h"
#include "timed_process_controller.h"
#include "travel.h"
#include "world_process.h"

#include "../ai/agents/agents_updater.h"


namespace Core {

void World::update(int delta) {
    MovementUpdater::update(delta);

    for (Actions::ActionPtr& actionPtr: _actions) {
        actionPtr->update(delta);
    }

    for (Actions::ActionPtr& actionPtr: _actions) {
        if (!actionPtr->isValid() || actionPtr->isFinished() || !actionPtr->isRunning()) {
            // TODO: Check what is happening here
            actionPtr->getActor().removeAction();
        }
    }

    auto iter = std::remove_if(_actions.begin(), _actions.end(), [](auto& action) {
        return !action->isValid() || action->isFinished() || !action->isRunning();
    });
    _actions.erase(iter, _actions.end());
}

World::World(TimedProcessController& timedProcessController, GlobalMessageBus& appMessageManager, WorldMap& worldMap) :
        WorldInventory(appMessageManager),
        AgentLocator(worldMap),
        MovementUpdater(worldMap, *this),
        _actionManager(*this),
        _actorsRegistry(),
        _globalMessageManager(appMessageManager),
        _worldMap(worldMap) {
    ProcessPtr ptr = std::make_unique<WorldProcess>(*this);
    timedProcessController.addProcess(std::move(ptr));
    timedProcessController.addProcess(std::make_unique<AI::Agents::AgentNeedsUpdater>(_actorsRegistry));
}

std::unordered_set<std::string> const& World::getActions(const AI::Agents::Agent& actor) {
    const auto locationName = getAgentsLocation(actor);
    if (locationName) {
        const auto location = _worldMap.getLocation(*locationName);
        return location->getType().getActions();
    }
    return _worldMap.getLocation(kPositionInRoute)->getType().getActions();
}

void World::doAction(AI::Agents::Agent& actor, const std::string& action) {
    const auto& placeActions = getActions(actor);
    if (placeActions.find(action) != placeActions.end()) {
        Actions::ActionPtr actionInstance = _actionManager.getAction(action, actor);
        actor.setAction(actionInstance);
        _actions.push_back(actionInstance);
    }
}

AI::Agents::AgentsRegistry& World::getAgentsRegistry() {
    return _actorsRegistry;
}

const AI::Agents::AgentsRegistry& World::getAgentsRegistry() const {
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

GlobalMessageBus& World::getGlobalMessageManager() {
    return _globalMessageManager;
}

bool World::hasLocation(const std::string& locationType) {
    const auto& locations = _worldMap.getLocations();
    auto iter = std::find_if(locations.begin(), locations.end(),
                             [&locationType](const auto& locationIter) {
                                 return locationIter.second->getType().getName() == locationType;
                             });
    return iter != locations.end();
}

} // namespace Core