//
// Created by TriD on 01.10.2021.
//

#ifndef EXP_ACTIONS_CONSTANTS_H
#define EXP_ACTIONS_CONSTANTS_H

namespace Core::Actions {

constexpr char kWellLocationName[] = "well";

constexpr char kActionDrinkExecutedMessage[] = "Ooh! Not thirsty anymore!";

constexpr int kActionDrinkTime = 1000;
constexpr int kActionEatTime = 1000;
constexpr int kActionHuntTime = 1000;
constexpr int kWoodcuttingTime = 1000;

constexpr char kActionEat[] = "eat";
constexpr char kActionRest[] = "rest";
constexpr char kActionHunt[] = "hunt";
constexpr char kActionCutWood[] = "cut_wood";
constexpr char kActionDrink[] = "drink";

constexpr char kItemFood[] = "food";
constexpr char kItemWood[] = "wood";

} // namespace Core::Actions

#endif //EXP_ACTIONS_CONSTANTS_H
