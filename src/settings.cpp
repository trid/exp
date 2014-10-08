#include "settings.h"
#include "script_manager.h"

Settings::Settings() {
    ScriptManager::getInstance().loadScript("scripts/settings.lua");
}

const string &Settings::getStringParameter(const string& name) {
    pushSettingToStack(name);
    return lua_tostring(ScriptManager::getInstance().getState(), -1);
}

bool Settings::getBoolParameter(const string& name) {
    pushSettingToStack(name);
    return (bool)lua_toboolean(ScriptManager::getInstance().getState(), -1);
}

void Settings::pushSettingToStack(string const &name) {
    lua_State *state = ScriptManager::getInstance().getState();
    lua_getglobal(state, "settings");
    lua_pushstring(state, name.c_str());
    lua_gettable(state, -2);
}

int Settings::getIntParameter(const string& name) {
    pushSettingToStack(name);
    return lua_tointeger(ScriptManager::getInstance().getState(), -1);
}