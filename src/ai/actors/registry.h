#ifndef ACTOR_REGISTRY_H
#define ACTOR_REGISTRY_H

#include "vector"
#include "actor.h"
#include "../../process.h"
#include "../../application.h"

namespace Core::AI::Actors {

class Actor;

class ActorsRegistry {
public:
    class ActorRegistryProcess : public Core::Process {
    public:
        explicit ActorRegistryProcess(ActorsRegistry& actorsRegistry);

        void update(int delta) override;
        bool finished() override;

    private:
        ActorsRegistry& _actorsRegistry;
    };

    class ActorStatusUpdateProcess : public Core::Process {
    public:
        explicit ActorStatusUpdateProcess(ActorsRegistry& actorRegistry);

        void update(int delta) override;
        bool finished() override;
    private:
        int time = 0;
        int interval = 500;

        ActorsRegistry& _actorRegistry;
        void updateNeeds(Actor* actor) const;
    };

public:
    explicit ActorsRegistry(Core::Application& application);

    Actor& createActor(View::ViewFacade& view, Core::World& world, View::Widgets::GUIPanel& guiPanel);
    Actor* getActor(int id);
    [[nodiscard]] const std::vector<Actor*>& getActors() const;
    std::vector<Actor*>& getActors();
    void update();

    int getLastId() { return actors.back()->getID(); }

private:
    std::vector<Actor*> actors;
    int nextId = 0;
};

} // namespace Core::AI::Actors

#endif // ACTOR_REGISTRY_H