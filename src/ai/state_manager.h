#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <string>
#include <unordered_map>

#include "state.h"
#include "lua5.1/lua.hpp"

class ScriptManager;
class World;

class StateManager {
public:
    StateManager(ScriptManager& scriptManager, World& world);

    State* getState(const std::string& name);

    void registerScriptedStates();
    void registerScriptedState(char const *tableName, char const *stateName);
private:
    void registerStates(World& world);

    std::unordered_map<std::string, State*> _states;
    ScriptManager& _scriptManager;
};

#endif