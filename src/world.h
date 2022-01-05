#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <cmath>
#include <list>
#include <memory>
#include <string>
#include <unordered_set>

#include "actions/action_manager.h"

#include "ai/actors/registry.h"

#include "application.h"
#include "global_message_manager.h"
#include "location_type_manager.h"
#include "message_manager.h"
#include "process.h"
#include "world_map.h"

#include "view/map_object_view.h"
#include "view/scene_object_manager.h"


namespace Core {

namespace AI::Actors {
class Agent;
} // namespace AI::Actors

struct Travel;

typedef std::shared_ptr<Travel> TravelPtr;

class World {
public:
    World(Application& application, GlobalMessageManager& appMessageManager);

    TravelPtr moveActor(AI::Actors::Agent* actor, std::string const& dest);

    void update(int delta);

    int getFood() const;
    [[maybe_unused]] void setFood(int food);

    int getWood() const;
    [[maybe_unused]] void setWood(int wood);

    void addWood(int i);
    void addFood(int i);

    void unloadWood(AI::Actors::Agent& agent);
    void unloadFood(AI::Actors::Agent& agent);

    void removeFood();

    void setAgentLocation(AI::Actors::Agent& agent, const std::string& position) const;

    std::unordered_set<std::string> const& getActions(AI::Actors::Agent* actor);

    void doAction(AI::Actors::Agent* actor, const std::string& action);

    MessageManager& getMessageManager();

    AI::Actors::AgentsRegistry& getAgentsRegistry();
    const AI::Actors::AgentsRegistry& getAgentsRegistry() const;

    const WorldMap& getWorldMap() const;
    WorldMap& getWorldMap();

    const LocationTypeManager& getLocationTypeManager() const;

    GlobalMessageManager& getGlobalMessageManager();

    boost::optional<const std::string&> getAgentsLocation(const AI::Actors::AgentPositioningData& agent) const;
private:
    std::list<TravelPtr> inRoute;
    int wood = 0;
    int food = 0;

    //TODO: Remove me with hardcoded actions
    std::unordered_set<std::string> homeActions;
    std::unordered_set<std::string> forestActions;
    std::unordered_set<std::string> wellActions;

    std::list<Actions::ActionPtr> actions;

    Actions::ActionManager _actionManager;
    AI::Actors::AgentsRegistry _actorsRegistry;
    MessageManager _messageManager;
    LocationTypeManager _locationTypeManager;
    WorldMap _worldMap;
    GlobalMessageManager& _globalMessageManager;
};

} // namespace Core

#endif // WORLD_H