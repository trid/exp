#ifndef ACTOR_REGISTRY_H
#define ACTOR_REGISTRY_H

#include "vector"
#include "actor.h"
#include "../process.h"
#include "../application.h"

using std::vector;

class Actor;

class ActorsRegistry {
public:
    class ActorRegistryProcess: public Process{
    public:
        ActorRegistryProcess(ActorsRegistry& actorsRegistry);

        virtual void update(int delta);
        virtual bool finished();

    private:
        ActorsRegistry& _actorsRegistry;
    };
    class ActorStatusUpdateProcess: public Process {
    public:
        ActorStatusUpdateProcess(ActorsRegistry& actorRegistry);

        virtual void update(int delta);
        virtual bool finished();
    private:
        int time = 0;
        int interval = 500;

        ActorsRegistry& _actorRegistry;
    };

public:
    ActorsRegistry(Application& application);

    Actor& createActor(View& view, World& world);
    Actor * getActor(int id);
    const vector<Actor*>& getActors();
    void killActor(int id);
    void update();
    int getLastId() { return actors.back()->getID(); }
private:
    vector<Actor*> actors;
    int nextId = 0;
};

#endif // ACTOR_REGISTRY_H