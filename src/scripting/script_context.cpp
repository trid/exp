#include "script_context.h"

ScriptContext::ScriptContext() {
    _state = luaL_newstate();
}

void ScriptContext::loadScript(const string &path) {
    luaL_dofile(_state, path.c_str());
}

void ScriptContext::registerFunction(const string &name, lua_CFunction function) {
    lua_register(_state, name.c_str(), function);
}

lua_State* ScriptContext::getState() const {
    return _state; }

ScriptContext::~ScriptContext() {
    lua_close(_state);
}
