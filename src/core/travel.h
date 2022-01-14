//
// Created by TriD on 01.11.2021.
//

#ifndef EXP_TRAVEL_H
#define EXP_TRAVEL_H

#include <string>

#include "location_type_manager.h"

namespace Core {

namespace AI::Agents {
class Agent;
} // namespace AI::Agents

class AgentLocator;
class World;
class WorldMap;

class Travel {
public:
    Travel(AI::Agents::Agent& agent, const std::string& dest, const WorldMap& worldMap,
           const AgentLocator& locator);

    void update(int delta);

    //Returns true if actor finished its way
    [[nodiscard]] bool finished() const;

private:
    AI::Agents::Agent& _agent;
    std::string _dest;
    double _dx, _dy;
    const AgentLocator& _agentLocator;

};

} // namespace Core

#endif //EXP_TRAVEL_H
