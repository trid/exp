//
// Created by TriD on 02.10.2021.
//

#include "settings_reader.h"

#include "../core/constants.h"

namespace Scripting {

std::string SettingsReader::getStringParameter(const std::string& name) const {
    pushSettingNameToStack(name);
    auto res = lua_tostring(_settingsScriptContext.getState(), -1);
    cleanStack();
    return res;
}

bool SettingsReader::getBoolParameter(const std::string& name) const {
    pushSettingNameToStack(name);
    auto res = static_cast<bool>(lua_toboolean(_settingsScriptContext.getState(), -1));
    cleanStack();
    return res;
}

int SettingsReader::getIntParameter(const std::string& name) const {
    pushSettingNameToStack(name);
    auto res = lua_tointeger(_settingsScriptContext.getState(), -1);
    cleanStack();
    return res;
}

void SettingsReader::pushSettingNameToStack(const std::string& name) const {
    lua_State* state = _settingsScriptContext.getState();
    lua_getglobal(state, Core::kSettingsKey);
    lua_pushstring(state, name.c_str());
    lua_gettable(state, -2);
}

SettingsReader::SettingsReader(const std::string& settingsPath) {
    _settingsScriptContext.loadScript(settingsPath);
}

void SettingsReader::cleanStack() const {
    lua_pop(_settingsScriptContext.getState(), 2);
}

} // namespace Scripting