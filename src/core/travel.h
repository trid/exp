//
// Created by TriD on 01.11.2021.
//

#ifndef EXP_TRAVEL_H
#define EXP_TRAVEL_H

#include <string>

#include "location_type_manager.h"

namespace Core {

namespace AI::Actors {
class Agent;
} // namespace AI::Actors

class AgentLocator;
class World;
class WorldMap;

class Travel {
public:
    Travel(AI::Actors::Agent& agent, const std::string& dest, const WorldMap& worldMap,
           const AgentLocator& locator);

    void update(int delta);

    //Returns true if actor finished its way
    [[nodiscard]] bool finished() const;

private:
    AI::Actors::Agent& _agent;
    std::string _dest;
    double _dx, _dy;
    const AgentLocator& _agentLocator;

};

} // namespace Core

#endif //EXP_TRAVEL_H
