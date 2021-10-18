//
// Created by TriD on 18.10.2021.
//

#include "inventory.h"


namespace Core::AI::Actors {

void Inventory::addItem() {
    if (_inventory < _inventoryLimit) {
        _inventory++;
    }
}

int Inventory::getInventoryLimit() {
    return _inventoryLimit;
}

int Inventory::getInventory() const { return _inventory; }

void Inventory::setInventory(int inventory) { _inventory = inventory; }


}