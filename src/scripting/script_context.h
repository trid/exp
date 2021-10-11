#ifndef SCRIPT_MANAGER_H
#define SCRIPT_MANAGER_H

#include <string>
#include <vector>

#include "lua.hpp"

#include "../external/sol/sol.hpp"

namespace Scripting {

class ScriptContext {
public:
    void loadScript(const std::string& path);
    void registerFunction(const std::string& name, lua_CFunction function);
    [[nodiscard]] lua_State* getState() const;

    template <typename... Ts>
    void callFunctionInTable(const std::string& tableName, const std::string& functionName, Ts... args) {
        _state[tableName][functionName](args...);
    }

protected:
    sol::state& getState();

private:
    sol::state _state;
};

} // namespace Scripting

#endif // SCRIPT_MANAGER_H