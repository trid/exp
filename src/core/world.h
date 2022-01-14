#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
#include <unordered_set>

#include "../actions/action_manager.h"

#include "../ai/agents/agent_registry.h"

#include "agent_locator.h"
#include "application.h"
#include "global_message_bus.h"
#include "location_type_manager.h"
#include "movement_updater.h"
#include "process.h"
#include "world_map.h"
#include "world_inventory.h"

#include "../view/map_object_view.h"
#include "../view/scene_object_renderer.h"


namespace Core {

namespace AI::Agents {
class Agent;
} // namespace AI::Agents

class TimedProcessController;

class World: public WorldInventory, public AgentLocator, public MovementUpdater {
public:
    World(TimedProcessController& timedProcessController, GlobalMessageBus& appMessageManager, WorldMap& worldMap);

    void update(int delta);

    std::unordered_set<std::string> const& getActions(const AI::Agents::Agent& actor);

    void doAction(AI::Agents::Agent& actor, const std::string& action);

    AI::Agents::AgentsRegistry& getAgentsRegistry();
    const AI::Agents::AgentsRegistry& getAgentsRegistry() const;

    const WorldMap& getWorldMap() const;
    WorldMap& getWorldMap();

    const LocationTypeManager& getLocationTypeManager() const;

    GlobalMessageBus& getGlobalMessageManager();

private:
    std::vector<Actions::ActionPtr> _actions;

    Actions::ActionManager _actionManager;
    AI::Agents::AgentsRegistry _actorsRegistry;
    LocationTypeManager _locationTypeManager;
    WorldMap& _worldMap;
    GlobalMessageBus& _globalMessageManager;
};

} // namespace Core

#endif // WORLD_H