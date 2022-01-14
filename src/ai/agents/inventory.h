//
// Created by TriD on 18.10.2021.
//

#ifndef EXP_INVENTORY_H
#define EXP_INVENTORY_H

#include <string>
#include <unordered_map>

namespace Core::AI::Agents {

class Inventory {
public:
    void addItem(const std::string& item);

    int getItemsCount(const std::string& item) const;
    int getAllItemsCount() const;
    void removeItems(const std::string& item, int amount);
    void removeAllItems(const std::string& item);

    int getInventoryLimit() const;

private:
    std::unordered_map<std::string, int> _inventory;
    int _inventoryLimit = 20;
};

} // namespace Core::AI::Agents

#endif //EXP_INVENTORY_H
