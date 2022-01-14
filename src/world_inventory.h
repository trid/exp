//
// Created by TriD on 06.01.2022.
//

#ifndef EXP_WORLD_INVENTORY_H
#define EXP_WORLD_INVENTORY_H

#include <unordered_map>

#include "global_message_manager.h"

namespace Core::AI::Actors {
class Agent;
} // namespace Core::AI::Actors

namespace Core {

class GlobalMessageManager;

class WorldInventory {
public:
    explicit WorldInventory(GlobalMessageManager& globalMessageManager);

    unsigned int getResourceCount(const std::string& resource) const;
    void setResourceCount(const std::string& resource, unsigned int amount);

    void removeResource(const std::string& resource, unsigned int amount);

    void unloadResource(AI::Actors::Agent& agent, const std::string& resource);

private:
    std::unordered_map<std::string, unsigned int> _resources;

    GlobalMessageManager& _globalMessageManager;
};

} // namespace Core

#endif //EXP_WORLD_INVENTORY_H
