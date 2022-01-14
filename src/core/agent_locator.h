//
// Created by TriD on 06.01.2022.
//

#ifndef EXP_AGENT_LOCATOR_H
#define EXP_AGENT_LOCATOR_H

#include <boost/optional.hpp>

namespace Core {

namespace AI::Agents {
class Agent;
class AgentPositioningData;
}

class WorldMap;

class AgentLocator {
public:
    AgentLocator(const WorldMap& worldMap);

    void setAgentLocation(AI::Agents::Agent& agent, const std::string& position) const;

    [[nodiscard]] boost::optional<const std::string&>
    getAgentsLocation(const AI::Agents::AgentPositioningData& agent) const;

private:
    const WorldMap& _worldMap;
};

} // namespace Core

#endif //EXP_AGENT_LOCATOR_H
