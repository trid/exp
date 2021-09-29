#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <string>

#include "lua5.1/lua.hpp"

using std::string;

class ScriptManager {
private:
    lua_State* state;
public:
    ScriptManager();

    void loadScript(const string& path);
    void registerFunctions();
    void registerFunction(const string& name, lua_CFunction function);
    lua_State* getState() {
        return state; }
};

#endif