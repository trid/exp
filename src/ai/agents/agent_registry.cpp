#include "agent_registry.h"

#include <sstream>

#include "../constants.h"
#include "../../core/timed_process_controller.h"
#include "../../core/world.h"


namespace Core::AI::Agents {

AgentsRegistry::AgentsRegistry(TimedProcessController& timedProcessController) {}

const std::vector<Agent>& AgentsRegistry::getActors() const {
    return _agents;
}

std::vector<Agent>& AgentsRegistry::getActors() {
    return _agents;
}

Agent& AgentsRegistry::createAgent(Core::World& world) {
    auto& agent = _agents.emplace_back(nextId, world.getGlobalMessageManager());
    nextId++;
    return agent;
}

boost::optional<Agent&> AgentsRegistry::getAgent(int id) {
    return (_agents.size() > id) ? boost::optional<Agent&>(_agents[id]) : boost::none;
}

boost::optional<const Agent&> AgentsRegistry::getAgent(int id) const {
    return (_agents.size() > id) ? boost::optional<const Agent&>(_agents[id]) : boost::none;
}

int AgentsRegistry::getLastId() const { return _agents.back().getID(); }

} // namespace Core::AI::Agents