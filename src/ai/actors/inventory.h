//
// Created by TriD on 18.10.2021.
//

#ifndef EXP_INVENTORY_H
#define EXP_INVENTORY_H

namespace Core::AI::Actors {

class Inventory {
public:
    void addItem();

    [[nodiscard]] int getInventory() const;
    void setInventory(int inventory);

    int getInventoryLimit();

private:
    int _inventory = 0;
    int _inventoryLimit = 20;
};

}

#endif //EXP_INVENTORY_H
