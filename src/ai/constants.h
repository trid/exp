//
// Created by TriD on 01.10.2021.
//

#ifndef EXP_AI_CONSTANTS_H
#define EXP_AI_CONSTANTS_H

namespace Core::AI {

constexpr char kNoStateStateName[] = "NoState";
constexpr char kHungryStateName[] = "Hungry";
constexpr char kThirstyStateName[] = "Thirsty";

constexpr char kMaxFoodParameter[] = "maxFood";
constexpr char kMaxWaterParameter[] = "maxWater";

constexpr char kTemporaryActorNamePrefix[] = "actor";

constexpr char kScriptExecuteMethodName[] = "execute";
constexpr char kScriptExitMethodName[] = "exit";
constexpr char kScriptEnterMethodName[] = "enter";
constexpr char kScriptProcessMessageMethodName[] = "processMessage";

constexpr char kStateFinishedEnterMessage[] = "Yup! I've finished!";
constexpr char kStateFinishedExecuteMessage[] = "Enjoing myself.";
constexpr char kStateFinishedExitMessage[] = "Returning to work";
constexpr char kStateStartEnterMessage[] = "Waked up.";
constexpr char kStateStartExecuteWorkMessage[] = "What shall I do now...";
constexpr char kStateStartExecuteRestMessage[] = "I can rest!";
constexpr char kStateStartExitMessage[] = "Start to do something.";
constexpr char kStateWoodcuttingEnterMessage[] = "Start cutting wood";
constexpr char kStateWoodcuttingExecuteMessage[] = "Cutting wood! Loving wood! Wood is like my wife!";
constexpr char kStateWoodcuttingExitMessage[] = "Finished cutting wood";
constexpr char kInventoryIsFullMessage[] = "Inventory is too heavy. Returning home";

constexpr char kStateStartName[] = "StateStart";
constexpr char kStateFinishedName[] = "StateFinished";
constexpr char kStateWoodcuttingName[] = "StateWoodcutting";
constexpr char kStateWoodcutterInRoute[] = "StateWoodcutterInRoute";

constexpr char kForestLocationName[] = "forest";
constexpr char kHomeLocationName[] = "home";

} // namespace Core::AI

#endif //EXP_AI_CONSTANTS_H
