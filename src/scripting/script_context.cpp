#include "script_context.h"

ScriptContext::ScriptContext() {
    _state = luaL_newstate();
}

void ScriptContext::loadScript(const std::string &path) {
    luaL_dofile(_state, path.c_str());
}

void ScriptContext::registerFunction(const std::string &name, lua_CFunction function) {
    lua_register(_state, name.c_str(), function);
}

lua_State* ScriptContext::getState() const {
    return _state; }

ScriptContext::~ScriptContext() {
    lua_close(_state);
}

void ScriptContext::callFunctionInTable(const std::string& tableName, const std::string& functionName,
                                        std::vector<void*> args) {
    lua_getglobal(_state, tableName.c_str());
    lua_pushstring(_state, functionName.c_str());
    lua_gettable(_state, -2);
    if (lua_isfunction(_state, -1)) {
        lua_remove(_state, -2);
        for (auto item: args) {
            lua_pushlightuserdata(_state, item);
        }
        lua_call(_state, args.size(), 0);
    }
}
