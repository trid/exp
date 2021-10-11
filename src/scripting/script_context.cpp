#include "script_context.h"

namespace Scripting {

void ScriptContext::loadScript(const std::string& path) {
    auto result = _state.script_file(path);
    if (!result.valid()) {
        std::cout << "Failed to load '" << path << "'" << std::endl;
        sol::error err = result;
        std::cout << err.what() << std::endl;
    }
}

void ScriptContext::registerFunction(const std::string& name, lua_CFunction function) {
    lua_register(_state, name.c_str(), function);
}

lua_State* ScriptContext::getState() const {
    return _state.lua_state();
}

sol::state& ScriptContext::getState() {
    return _state;
}

} // namespace Scripting