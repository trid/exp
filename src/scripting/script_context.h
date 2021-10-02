#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <string>

#include "lua5.1/lua.hpp"

class ScriptContext {
public:
    ScriptContext();
    virtual ~ScriptContext();

    void loadScript(const std::string& path);
    void registerFunction(const std::string& name, lua_CFunction function);
    [[nodiscard]] lua_State* getState() const;
private:
    lua_State* _state;
};

#endif