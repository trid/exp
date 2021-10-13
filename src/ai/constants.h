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

// Behaviours
constexpr char kRunFunctionName[] = "run";
constexpr char kTransitionFunctionName[] = "transition";

constexpr char kForestLocationName[] = "forest";
constexpr char kHomeLocationName[] = "home";

} // namespace Core::AI

#endif //EXP_AI_CONSTANTS_H
