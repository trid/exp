#ifndef ACTOR_REGISTRY_H
#define ACTOR_REGISTRY_H

#include "vector"
#include "actor.h"
#include "../process.h"
#include "../application.h"

namespace Core::AI {

class Actor;

class ActorsRegistry {
public:
    class ActorRegistryProcess : public Core::Process {
    public:
        ActorRegistryProcess(ActorsRegistry& actorsRegistry);

        virtual void update(int delta);
        virtual bool finished();

    private:
        ActorsRegistry& _actorsRegistry;
    };

    class ActorStatusUpdateProcess : public Core::Process {
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
    ActorsRegistry(Core::Application& application);

    Actor& createActor(View::ViewFacade& view, Core::World& world, View::Widgets::GUIPanel& guiPanel);
    Actor* getActor(int id);
    const std::vector<Actor*>& getActors() const;
    std::vector<Actor*>& getActors();
    void killActor(int id);
    void update();

    int getLastId() { return actors.back()->getID(); }

private:
    std::vector<Actor*> actors;
    int nextId = 0;
};

} // namespace Core::AI

#endif // ACTOR_REGISTRY_H