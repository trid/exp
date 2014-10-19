#include <algorithm>
#include <cmath>
#include <list>
#include <memory>
#include <string>
#include "message_manager.h"
#include "actor.h"
#include "process.h"
#include "view/map_object.h"
#include "view/scene_object_manager.h"

using std::string;
using std::remove_if;
using std::atan2;
using std::sqrt;

class Actor;

struct Travel {
    Actor* actor;
    string dest;
    double distancePassed;
    double distanceNeeded;
    double dx, dy;

    Travel(Actor* actor, const string& dest): actor(actor), dest(dest),
                                                       distancePassed(0)
    {
        MapObjectPtr mapObject = SceneObjectManager::getInstance().getMapObject(dest);
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
    static World& getWorld() {
        static World world;
        return world;
    };

    void moveActor(Actor *actor, string const &dest);
    void update(int delta);

    int getFood() const {
        return food;
    }

    void setFood(int food) {
        World::food = food;
    }

    int getWood() const {
        return wood;
    }

    void setWood(int wood) {
        World::wood = wood;
    }

    void addWood(int i) {
        wood += i;
    }

    void addFood(int i) {
        food += i;
    }

    void removeFood() {
        food--;
    }
private:
    World();

    std::list<TravelPtr> inRoute;
    int wood = 0;
    int food = 0;
};

class WorldProcess: public Process {

public:
    virtual void update(int delta);

    virtual bool finished();
};