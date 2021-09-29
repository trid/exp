#include "settings.h"
#include "script_manager.h"

Settings::Settings(ScriptManager& scriptManager):
    _scriptManager(scriptManager)
{
    _scriptManager.loadScript("scripts/settings.lua");
}

string Settings::getStringParameter(const string& name) const {
    pushSettingToStack(name);
    return lua_tostring(_scriptManager.getState(), -1);
}

bool Settings::getBoolParameter(const string& name) const {
    pushSettingToStack(name);
    return (bool)lua_toboolean(_scriptManager.getState(), -1);
}

void Settings::pushSettingToStack(string const &name) const {
    lua_State *state = _scriptManager.getState();
    lua_getglobal(state, "settings");
    lua_pushstring(state, name.c_str());
    lua_gettable(state, -2);
}

int Settings::getIntParameter(const string& name) const {
    pushSettingToStack(name);
    return lua_tointeger(_scriptManager.getState(), -1);
}