//
// Created by TriD on 06.01.2022.
//

#include "world_inventory.h"

#include "constants.h"
#include "message_data.h"

#include "../ai/agents/agent.h"
#include "../actions/constants.h"

namespace Core {

WorldInventory::WorldInventory(GlobalMessageBus& globalMessageManager) : _globalMessageManager(
        globalMessageManager) {}

unsigned int WorldInventory::getResourceCount(const std::string& resource) const {
    auto iter = _resources.find(resource);
    if (iter != _resources.end()) {
        return iter->second;
    }
    return 0;
}

void WorldInventory::setResourceCount(const std::string& resource, unsigned int amount) {
    _resources[resource] = amount;
}

void WorldInventory::removeResource(const std::string& resource, unsigned int amount) {
    auto currentAmount = _resources[resource];
    _resources[resource] = currentAmount >= amount ? currentAmount - amount : 0;
    _globalMessageManager.sendMessage(kResourceUpdatedMessage, MessageData{});
}

void WorldInventory::unloadResource(AI::Agents::Agent& agent, const std::string& resource) {
    _resources[resource] += agent.getItemsCount(resource);
    agent.removeAllItems(resource);
    _globalMessageManager.sendMessage(kResourceUpdatedMessage, MessageData{});
}

} // namespace Core