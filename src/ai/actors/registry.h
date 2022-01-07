#ifndef ACTOR_REGISTRY_H
#define ACTOR_REGISTRY_H

#include "vector"
#include "agent.h"
#include "../../process.h"

namespace Core {
class TimedProcessController;
} // namespace Core

namespace Core::AI::Actors {

class Agent;

class AgentsRegistry {
public:
    class ActorStatusUpdateProcess : public Core::Process {
    public:
        explicit ActorStatusUpdateProcess(AgentsRegistry& actorRegistry);

        void update(unsigned int delta) override;
        bool finished() override;
    private:
        int time = 0;
        int interval = 500;

        AgentsRegistry& _actorRegistry;
        void updateNeeds(Agent* actor) const;
    };

public:
    explicit AgentsRegistry(TimedProcessController& timedProcessController);

    Agent& createAgent(Core::World& world);
    [[nodiscard]] boost::optional<Agent&> getAgent(int id);
    [[nodiscard]] boost::optional<const Agent&> getAgent(int id) const;
    [[nodiscard]] const std::vector<Agent*>& getActors() const;
    [[nodiscard]] std::vector<Agent*>& getActors();

    [[nodiscard]] int getLastId() const;

private:
    std::vector<Agent*> actors;
    int nextId = 0;
};

} // namespace Core::AI::Actors

#endif // ACTOR_REGISTRY_H