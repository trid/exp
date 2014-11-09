#include "vector"
#include "actor.h"
#include "../process.h"

using std::vector;

class Actor;

class ActorsRegistry {
public:
    static ActorsRegistry& getRegistry() {
        static ActorsRegistry ar;
        return ar;
    };

    Actor& createActor();
    Actor * getActor(int id);
    const vector<Actor*>& getActors();
    void killActor(int id);
    void update();
    int getLastId() { return actors.back()->getID(); }
private:
    vector<Actor*> actors;
    int nextId = 0;

    ActorsRegistry();
public:
    class ActorRegistryProcess: public Process{
    public:
        virtual void update(int delta);
        virtual bool finished();
    };
    class ActorStatusUpdateProcess: public Process {
    private:
        int time = 0;
        int interval = 500;
    public:
        virtual void update(int delta);
        virtual bool finished();
    };
};