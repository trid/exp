//
// Created by TriD on 01.11.2021.
//

#ifndef EXP_TRAVEL_H
#define EXP_TRAVEL_H

#include <string>

namespace Core {

namespace AI::Actors {
class Agent;
} // namespace AI::Actors

class World;
class WorldMap;

struct Travel {
    AI::Actors::Agent* actor;
    std::string dest;
    double distancePassed;
    double distanceNeeded;
    double dx, dy;
    World& world;

    Travel(AI::Actors::Agent* actor, const std::string& dest, const WorldMap& worldMap, World& world);

    void update(int delta);

    //Returns true if actor finished its way
    [[nodiscard]] bool finished() const { return distancePassed >= distanceNeeded; }
};

} // namespace Core

#endif //EXP_TRAVEL_H
