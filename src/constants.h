//
// Created by TriD on 30.09.2021.
//

#ifndef EXP_CONSTANTS_H
#define EXP_CONSTANTS_H

namespace Core {

// Location type manager
constexpr char kLocationTypesPath[] = "res/locations/location_types.xml";
constexpr char kLocationTypesKey[] = "types";
constexpr char kLocationNameKey[] = "name";
constexpr char kLocationActionsKey[] = "actions";
constexpr char kLocationWidthKey[] = "width";
constexpr char kLocationHeightKey[] = "height";

// Scripting
constexpr char kInitScriptPath[] = "scripts/init.lua";
constexpr char kSettingsScriptPath[] = "scripts/settings.lua";
constexpr char kSettingsKey[] = "settings";

// World
const std::string kPositionInRoute{"In route"};

// Messages
constexpr char kFoodUpdatedMessage[] = "FOOD_UPDATED_MESSAGE";
constexpr char kWoodUpdatedMessage[] = "WOOD_UPDATED_MESSAGE";
constexpr char kFinishedMovingMessage[] = "FINISHED_MOVING";
constexpr char kAgentPhraseMessage[] = "AGENT_PHRASE";

constexpr char kAgentPhraseMessageKey[] = "message";

// Settings
constexpr char kScreenWidthParameterKey[] = "screen_width";
constexpr char kScreenHeightParameterKey[] = "screen_height";

#endif //EXP_CONSTANTS_H

} // namespace Core