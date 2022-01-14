//
// Created by TriD on 06.01.2022.
//

#ifndef EXP_MOVEMENT_UPDATER_H
#define EXP_MOVEMENT_UPDATER_H

#include <memory>
#include <unordered_map>

namespace Core {

namespace AI::Agents {
class Agent;
}

class AgentLocator;
struct Travel;
class WorldMap;

typedef std::shared_ptr<Travel> TravelPtr;

class MovementUpdater {
public:
    MovementUpdater(const WorldMap& worldMap, const AgentLocator& locator);

    TravelPtr moveActor(AI::Agents::Agent& actor, std::string const& dest);

    void update(int delta);
private:
    std::unordered_map<int, TravelPtr> _inRoute;

    const WorldMap& _worldMap;
    const AgentLocator& _agentLocator;
};

} // namespace Core

#endif //EXP_MOVEMENT_UPDATER_H
