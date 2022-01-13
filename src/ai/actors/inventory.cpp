//
// Created by TriD on 18.10.2021.
//

#include "inventory.h"

#include <numeric>

namespace Core::AI::Actors {

void Inventory::addItem(const std::string& item) {
    if (getAllItemsCount() < _inventoryLimit) {
        _inventory[item]++;
    }
}

int Inventory::getInventoryLimit() const {
    return _inventoryLimit;
}

int Inventory::getAllItemsCount() const {
    int amount = std::accumulate(_inventory.begin(), _inventory.end(), 0,
                                 [](int op1, auto& op2) { return op1 + op2.second; });
    return amount;
}

int Inventory::getItemsCount(const std::string& item) const {
    const auto it = _inventory.find(item);
    if (it != _inventory.end()) {
        return it->second;
    }
    return 0;
}

void Inventory::removeItems(const std::string& item, int amount) {
    auto existing = _inventory[item];
    _inventory[item] = existing > amount ? existing - amount : 0;
}

void Inventory::removeAllItems(const std::string& item) {
    _inventory[item] = 0;
}


}