//
// Created by TriD on 30.09.2021.
//

#ifndef EXP_CONSTANTS_H
#define EXP_CONSTANTS_H

// Location type manager
constexpr char kLocationTypesPath[] = "res/locations/location_types.xml";
constexpr char kLocationTypesKey[] = "types";
constexpr char kLocationNameKey[] = "name";
constexpr char kLocationActionsKey[] = "actions";

// Scripts
constexpr char kInitScriptPath[] = "scripts/init.lua";
constexpr char kSettingsScriptPath[] = "scripts/settings.lua";
constexpr char kScriptMessagePrefix[] = "LUA: ";
constexpr char kSettingsKey[] = "settings";

// World
constexpr char kPositionInRoute[] = "In route";
constexpr char kActionEat[] = "eat";
constexpr char kActionRest[] = "rest";
constexpr char kActionHunt[] = "hunt";
constexpr char kActionCutWood[] = "cut_wood";
constexpr char kActionDrink[] = "drink";

// Messages
constexpr char kFoodUpdatedMessage[] = "FOOD_UPDATED_MESSAGE";
constexpr char kWoodUpdatedMessage[] = "WOOD_UPDATED_MESSAGE";

// Settings
constexpr char kScreenWidthParameterKey[] = "screen_width";
constexpr char kScreenHeightParameterKey[] = "screen_height";

#endif //EXP_CONSTANTS_H
