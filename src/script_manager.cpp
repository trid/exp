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
    registerFunction("addFood", addFood);
    registerFunction("moveTo", moveTo);
    registerFunction("getThirsty", getThirsty);
    registerFunction("drink", drink);
    registerFunction("getPlace", getPlace);
    registerFunction("sendTo", sendTo);
    registerFunction("eat", eat);
    registerFunction("getFeed", getFeed);
    registerFunction("say", say);
    registerFunction("setName", setName);
    registerFunction("getInventory", getInventory);
    registerFunction("getInventorySize", getInventorySize);
    registerFunction("unloadWood", unloadWood);
    registerFunction("unloadFood", unloadFood);
    registerFunction("setReaction", setReaction);

    registerFunction("getMessageType", getMessageType);

    registerFunction("getStoredFood", getStoredFood);

    registerFunction("createActor", createActor);

    registerFunction("createSceneObject", createSceneObject);
}

void ScriptManager::registerFunction(const string &name, lua_CFunction function) {
    lua_register(state, name.c_str(), function);
}