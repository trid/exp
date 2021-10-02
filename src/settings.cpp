#include "settings.h"

#include "constants.h"
#include "script_context.h"

Settings::Settings():
    _scriptManager()
{
    _scriptManager.loadScript(kSettingsScriptPath);
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
    lua_getglobal(state, kSettingsKey);
    lua_pushstring(state, name.c_str());
    lua_gettable(state, -2);
}

int Settings::getIntParameter(const string& name) const {
    pushSettingToStack(name);
    return lua_tointeger(_scriptManager.getState(), -1);
}