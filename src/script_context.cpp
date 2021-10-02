#include "script_context.h"

ScriptContext::ScriptContext() {
    state = luaL_newstate();
}

void ScriptContext::loadScript(const string &path) {
    luaL_dofile(state, path.c_str());
}

void ScriptContext::registerFunction(const string &name, lua_CFunction function) {
    lua_register(state, name.c_str(), function);
}

lua_State* ScriptContext::getState() const {
    return state; }
