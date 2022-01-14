#ifndef ACTOR_REGISTRY_H
#define ACTOR_REGISTRY_H

#include <vector>

#include "../../core/process.h"

#include "agent.h"

namespace Core {
class TimedProcessController;
} // namespace Core

namespace Core::AI::Actors {

class Agent;

class AgentsRegistry {
public:
    explicit AgentsRegistry(TimedProcessController& timedProcessController);

    Agent& createAgent(Core::World& world);
    [[nodiscard]] boost::optional<Agent&> getAgent(int id);
    [[nodiscard]] boost::optional<const Agent&> getAgent(int id) const;
    [[nodiscard]] const std::vector<Agent>& getActors() const;
    [[nodiscard]] std::vector<Agent>& getActors();

    [[nodiscard]] int getLastId() const;

private:
    std::vector<Agent> _agents;
    int nextId = 0;
};

} // namespace Core::AI::Actors

#endif // ACTOR_REGISTRY_H