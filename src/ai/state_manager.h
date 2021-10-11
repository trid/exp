#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <string>
#include <unordered_map>

#include "state.h"
#include "lua5.1/lua.hpp"

namespace Scripting {
class ScriptContext;
} // namespace Scripting

namespace Core {
class World;
} // namespace Core

namespace Core::AI {

class StateManager {
public:
    explicit StateManager(Core::World& world);

    StateOpt getState(const std::string& name);

    void registerScriptedState(const std::string& tableName, const std::string& stateName,
                               Scripting::ScriptContext& scriptContext);
private:
    void registerStates(Core::World& world);

    std::unordered_map<std::string, StateUPtr> _states;
};

} // namespace Core::AI

#endif