#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <string>
#include <vector>

#include "lua5.1/lua.hpp"

class ScriptContext {
public:
    ScriptContext();
    virtual ~ScriptContext();

    void loadScript(const std::string& path);
    void registerFunction(const std::string& name, lua_CFunction function);
    [[nodiscard]] lua_State* getState() const;

    void callFunctionInTable(const std::string& tableName, const std::string& functionName, std::vector<void*> args);
private:
    lua_State* _state;
};

#endif