#include <algorithm>
#include <list>
#include <memory>
#include <string>
#include "message_manager.h"
#include "actor.h"

using std::string;
using std::remove_if;

class Actor;

struct Travel {
    Actor* actor;
    string dest;
    int distancePassed;
    int distanceNeeded;

    Travel(Actor* actor, const string& dest, int distance): actor(actor), dest(dest),
                                                       distancePassed(0), distanceNeeded(distance)
    {}

    //Returns true if actor finished it's way
    void update();
    bool finished() { return distancePassed >= distanceNeeded; }
};

typedef std::shared_ptr<Travel> TravelPtr;

class World {
public:
    static World& getWorld() {
        static World world;
        return world;
    };

    void moveActor(Actor *actor, string const &dest, int distance);
    void update();

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

    void addWood() {
        wood++;
    }

    void addFood() {
        food++;
    }
private:
    std::list<TravelPtr> inRoute;
    int wood = 0;
    int food = 0;
};