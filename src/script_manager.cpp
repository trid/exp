#include "script_manager.h"
#include "script_functions.h"

ScriptManager::ScriptManager() {
    state = luaL_newstate();
    registerFunctions();
}

void ScriptManager::loadScript(const string &path) {
    luaL_dofile(state, path.c_str());
}

void ScriptManager::registerFunctions() {
    registerFunction("print", print);
    registerFunction("registerScriptedState", registerScriptedState);
    registerFunction("setState", setState);
    registerFunction("updateSteps", updateSteps);
    registerFunction("resetSteps", resetSteps);
    registerFunction("getSteps", getSteps);
    registerFunction("addFood", addFood);
    registerFunction("moveTo", moveTo);
    registerFunction("getThirsty", getThirsty);
    registerFunction("drink", drink);
    registerFunction("getPlace", getPlace);
    registerFunction("sendTo", sendTo);
    registerFunction("eat", eat);
    registerFunction("getFeed", getFeed);

    registerFunction("getMessageType", getMessageType);
}

void ScriptManager::registerFunction(const string &name, lua_CFunction function) {
    lua_register(state, name.c_str(), function);
}
