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
    StateManager(Scripting::ScriptContext& scriptManager, Core::World& world);

    StateOpt getState(const std::string& name);

    void registerScriptedStates();
    void registerScriptedState(char const* tableName, char const* stateName);
private:
    void registerStates(Core::World& world);

    std::unordered_map<std::string, StateUPtr> _states;
    Scripting::ScriptContext& _scriptManager;
};

} // namespace Core::AI

#endif