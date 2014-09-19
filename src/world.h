#include <list>
#include <memory>

class Actor;

struct Travel {
    Actor& actor;
    int dest;
    int distancePassed;
    int distanceNeeded;

    Travel(Actor& actor, int dest, int distance): actor(actor), dest(dest),
                                                       distancePassed(0), distanceNeeded(distance)
    {}

    //Returns true if actor finished it's way
    bool update() { distancePassed++; return distanceNeeded == distancePassed; }
};

typedef std::shared_ptr<Travel> TravelPtr;

class World {
public:
    static World& getWorld() {
        static World world;
        return world;
    };

    void moveActor(Actor &actor, int dest);
    void update();

private:
    std::list<TravelPtr> inRoute;
};