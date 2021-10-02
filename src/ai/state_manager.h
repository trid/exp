#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <string>
#include <unordered_map>

#include "state.h"
#include "lua5.1/lua.hpp"

class ScriptContext;
class World;

class StateManager {
public:
    StateManager(ScriptContext& scriptManager, World& world);

    StateOpt getState(const std::string& name);

    void registerScriptedStates();
    void registerScriptedState(char const *tableName, char const *stateName);
private:
    void registerStates(World& world);

    std::unordered_map<std::string, StateUPtr> _states;
    ScriptContext& _scriptManager;
};

#endif