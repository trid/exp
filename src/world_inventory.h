//
// Created by TriD on 06.01.2022.
//

#ifndef EXP_WORLD_INVENTORY_H
#define EXP_WORLD_INVENTORY_H

#include "global_message_manager.h"

namespace Core::AI::Actors {
class Agent;
} // namespace Core::AI::Actors

namespace Core {

class GlobalMessageManager;

class WorldInventory {
public:
    explicit WorldInventory(GlobalMessageManager& globalMessageManager);

    [[nodiscard]] int getFood() const;
    void setFood(int food);

    [[nodiscard]] int getWood() const;
    void setWood(int wood);

    void addWood(int i);
    void addFood(int i);

    void unloadWood(AI::Actors::Agent& agent);
    void unloadFood(AI::Actors::Agent& agent);

    void removeFood();

private:
    int _wood = 0;
    int _food = 0;

    GlobalMessageManager& _globalMessageManager;
};

} // namespace Core

#endif //EXP_WORLD_INVENTORY_H
