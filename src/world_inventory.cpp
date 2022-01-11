//
// Created by TriD on 06.01.2022.
//

#include "world_inventory.h"

#include "constants.h"
#include "message_data.h"

#include "ai/actors/agent.h"
#include "actions/constants.h"

namespace Core {

WorldInventory::WorldInventory(GlobalMessageManager& globalMessageManager) : _globalMessageManager(
        globalMessageManager) {}

void WorldInventory::removeFood() {
    _food--;
    _globalMessageManager.sendMessage(kFoodUpdatedMessage, MessageData());
}

void WorldInventory::addFood(int i) {
    _food += i;
    _globalMessageManager.sendMessage(kFoodUpdatedMessage, MessageData());
}

void WorldInventory::addWood(int i) {
    _wood += i;
    _globalMessageManager.sendMessage(kWoodUpdatedMessage, MessageData());
}

int WorldInventory::getFood() const {
    return _food;
}

void WorldInventory::setFood(int food) {
    _food = food;
}

int WorldInventory::getWood() const {
    return _wood;
}

void WorldInventory::setWood(int wood) {
    _wood = wood;
}

void WorldInventory::unloadWood(AI::Actors::Agent& agent) {
    addWood(agent.getItemsCount(Actions::kItemWood));
    agent.removeAllItems(Actions::kItemWood);
}

void WorldInventory::unloadFood(AI::Actors::Agent& agent) {
    addFood(agent.getItemsCount(Actions::kItemFood));
    agent.removeAllItems(Actions::kItemFood);
}

} // namespace Core