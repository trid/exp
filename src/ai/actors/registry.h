#ifndef ACTOR_REGISTRY_H
#define ACTOR_REGISTRY_H

#include "vector"
#include "agent.h"
#include "../../process.h"
#include "../../application.h"

namespace Core::AI::Actors {

class Agent;

class AgentsRegistry {
public:
    class ActorRegistryProcess : public Core::Process {
    public:
        explicit ActorRegistryProcess(AgentsRegistry& actorsRegistry);

        void update(int delta) override;
        bool finished() override;

    private:
        AgentsRegistry& _actorsRegistry;
    };

    class ActorStatusUpdateProcess : public Core::Process {
    public:
        explicit ActorStatusUpdateProcess(AgentsRegistry& actorRegistry);

        void update(int delta) override;
        bool finished() override;
    private:
        int time = 0;
        int interval = 500;

        AgentsRegistry& _actorRegistry;
        void updateNeeds(Agent* actor) const;
    };

public:
    explicit AgentsRegistry(Core::Application& application);

    Agent& createAgent(Core::World& world, View::Widgets::GUIPanel& guiPanel);
    Agent* getAgent(int id);
    [[nodiscard]] const std::vector<Agent*>& getActors() const;
    std::vector<Agent*>& getActors();
    void update();

    int getLastId() { return actors.back()->getID(); }

private:
    std::vector<Agent*> actors;
    int nextId = 0;
};

} // namespace Core::AI::Actors

#endif // ACTOR_REGISTRY_H