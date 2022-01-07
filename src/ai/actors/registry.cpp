#include "registry.h"

#include <sstream>

#include "../constants.h"
#include "../timed_process_controller.h"
#include "../world.h"


namespace Core::AI::Actors {

AgentsRegistry::AgentsRegistry(TimedProcessController& timedProcessController) {}

const std::vector<Agent*>& AgentsRegistry::getActors() const {
    return actors;
}

std::vector<Agent*>& AgentsRegistry::getActors() {
    return actors;
}

Agent& AgentsRegistry::createAgent(Core::World& world) {
    auto* actor = new Agent(nextId, world.getGlobalMessageManager());
    nextId++;
    actors.push_back(actor);
    return *actor;
}

boost::optional<Agent&> AgentsRegistry::getAgent(int id) {
    return (actors.size() > id) ? boost::optional<Agent&>(*actors[id]) : boost::none;
}

boost::optional<const Agent&> AgentsRegistry::getAgent(int id) const {
    return (actors.size() > id) ? boost::optional<const Agent&>(*actors[id]) : boost::none;
}

int AgentsRegistry::getLastId() const { return actors.back()->getID(); }

} // namespace Core::AI::Actors