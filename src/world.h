#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <cmath>
#include <list>
#include <memory>
#include <string>
#include <unordered_set>

#include "actions/action_manager.h"
#include "application.h"
#include "location_type_manager.h"
#include "process.h"
#include "message_manager.h"
#include "world_map.h"

#include "ai/actor.h"
#include "ai/registry.h"

#include "view/map_object_view.h"
#include "view/scene_object_manager.h"
#include "global_message_manager.h"


namespace Core {

namespace AI {
class Actor;
} // namespace AI

struct Travel {
    AI::Actor* actor;
    string dest;
    double distancePassed;
    double distanceNeeded;
    double dx, dy;
    World& world;

    Travel(AI::Actor* actor, const string& dest, const WorldMap& worldMap, World& world);

    void update(int delta);

    //Returns true if actor finished its way
    [[nodiscard]] bool finished() const { return distancePassed >= distanceNeeded; }
};

typedef std::shared_ptr<Travel> TravelPtr;

class World {
public:
    World(Application& application, GlobalMessageManager& appMessageManager);

    TravelPtr moveActor(AI::Actor* actor, string const& dest);

    void update(int delta);

    int getFood() const;

    void setFood(int food) {
        World::food = food;
    }

    int getWood() const {
        return wood;
    }

    void setWood(int wood) {
        World::wood = wood;
    }

    void addWood(int i);

    void addFood(int i);

    void removeFood();

    std::unordered_set<string> const& getActions(AI::Actor* actor);

    void doAction(AI::Actor* actor, const string& action);

    MessageManager& getMessageManager();

    AI::ActorsRegistry& getActorsRegistry();

    const WorldMap& getWorldMap() const;
    WorldMap& getWorldMap();

    const LocationTypeManager& getLocationTypeManager() const;
private:
    std::list<TravelPtr> inRoute;
    int wood = 0;
    int food = 0;

    //TODO: Remove me with hardcoded actions
    std::unordered_set<string> homeActions;
    std::unordered_set<string> forestActions;
    std::unordered_set<string> wellActions;

    std::list<Actions::ActionPtr> actions;

    Actions::ActionManager _actionManager;
    AI::ActorsRegistry _actorsRegistry;
    MessageManager _messageManager;
    LocationTypeManager _locationTypeManager;
    WorldMap _worldMap;
    GlobalMessageManager& _appMessageManager;
};

class WorldProcess : public Process {
public:
    WorldProcess(World& world);

    virtual void update(int delta);

    virtual bool finished();

private:
    World& _world;
};

} // namespace Core

#endif // WORLD_H