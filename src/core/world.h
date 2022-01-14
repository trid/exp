#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
#include <unordered_set>

#include "../actions/action_manager.h"

#include "../ai/actors/agent_registry.h"

#include "agent_locator.h"
#include "application.h"
#include "global_message_manager.h"
#include "location_type_manager.h"
#include "movement_updater.h"
#include "process.h"
#include "world_map.h"
#include "world_inventory.h"

#include "../view/map_object_view.h"
#include "../view/scene_object_renderer.h"


namespace Core {

namespace AI::Actors {
class Agent;
} // namespace AI::Actors

class TimedProcessController;

class World: public WorldInventory, public AgentLocator, public MovementUpdater {
public:
    World(TimedProcessController& timedProcessController, GlobalMessageManager& appMessageManager, WorldMap& worldMap);

    void update(int delta);

    std::unordered_set<std::string> const& getActions(const AI::Actors::Agent& actor);

    void doAction(AI::Actors::Agent& actor, const std::string& action);

    AI::Actors::AgentsRegistry& getAgentsRegistry();
    const AI::Actors::AgentsRegistry& getAgentsRegistry() const;

    const WorldMap& getWorldMap() const;
    WorldMap& getWorldMap();

    const LocationTypeManager& getLocationTypeManager() const;

    GlobalMessageManager& getGlobalMessageManager();

private:
    std::vector<Actions::ActionPtr> _actions;

    Actions::ActionManager _actionManager;
    AI::Actors::AgentsRegistry _actorsRegistry;
    LocationTypeManager _locationTypeManager;
    WorldMap& _worldMap;
    GlobalMessageManager& _globalMessageManager;
};

} // namespace Core

#endif // WORLD_H