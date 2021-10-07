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
#include "location_manager.h"
#include "location_type_manager.h"
#include "process.h"
#include "message_manager.h"

#include "ai/actor.h"
#include "ai/registry.h"

#include "view/map_object_view.h"
#include "view/scene_object_manager.h"
#include "view/widgets/ui_message_manager.h"


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

    Travel(AI::Actor* actor, const string& dest, SceneObjectManager& sceneObjectManager, World& world)
            : actor(actor), dest(dest),
              distancePassed(0), world(world) {
        MapObjectPtr mapObject = sceneObjectManager.getMapObject(dest);
        int xDist = mapObject->getX() - actor->getX();
        int yDist = mapObject->getY() - actor->getY();
        double angle = atan2(yDist, xDist);
        dx = cos(angle) * actor->getSpeed() / 1000;
        dy = sin(angle) * actor->getSpeed() / 1000;
        distanceNeeded = (int) sqrt(xDist * xDist + yDist * yDist);
    }

    //Returns true if actor finished it's way
    void update(int delta);

    bool finished() { return distancePassed >= distanceNeeded; }
};

typedef std::shared_ptr<Travel> TravelPtr;

class World {
public:
    World(View& view, Application& application);

    void moveActor(AI::Actor* actor, string const& dest);

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

    SceneObjectManager& getSceneObjectManager();

    MessageManager& getMessageManager();

    LocationManager& getLocationManager();

private:
    std::list<TravelPtr> inRoute;
    int wood = 0;
    int food = 0;

    //TODO: Remove me with hardcoded actions
    std::unordered_set<string> homeActions;
    std::unordered_set<string> forestActions;
    std::unordered_set<string> wellActions;

    std::list<Actions::ActionPtr> actions;

    View& _view;
    SceneObjectManager _sceneObjectManager;
    Actions::ActionManager _actionManager;
    AI::ActorsRegistry _actorsRegistry;
    MessageManager _messageManager;
    LocationTypeManager _locationTypeManager;
    LocationManager _locationManager;
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