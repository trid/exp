//
// Created by TriD on 02.10.2021.
//

#include "settings_reader.h"

#include "../constants.h"

string SettingsReader::getStringParameter(const string& name) const {
    pushSettingNameToStack(name);
    auto res = lua_tostring(_settingsScriptContext.getState(), -1);
    cleanStack();
    return res;
}

bool SettingsReader::getBoolParameter(const string& name) const {
    pushSettingNameToStack(name);
    auto res = static_cast<bool>(lua_toboolean(_settingsScriptContext.getState(), -1));
    cleanStack();
    return res;
}

int SettingsReader::getIntParameter(const string& name) const {
    pushSettingNameToStack(name);
    auto res = lua_tointeger(_settingsScriptContext.getState(), -1);
    cleanStack();
    return res;
}

void SettingsReader::pushSettingNameToStack(string const &name) const {
    lua_State *state = _settingsScriptContext.getState();
    lua_getglobal(state, kSettingsKey);
    lua_pushstring(state, name.c_str());
    lua_gettable(state, -2);
}

SettingsReader::SettingsReader() {
    _settingsScriptContext.loadScript(kSettingsScriptPath);
}

void SettingsReader::cleanStack() const {
    lua_pop(_settingsScriptContext.getState(), 2);
}
