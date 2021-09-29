#include "state_manager.h"
#include "state_start.h"
#include "state_finished.h"
#include "state_woodcutting.h"
#include "../script_manager.h"
#include "scripted_state.h"

#include <boost/filesystem.hpp>

extern StateManager* g_stateManager;

using boost::filesystem::path;
using boost::filesystem::directory_iterator;
using boost::filesystem::directory_entry;

void StateManager::registerStates(World& world) {
    _states["StateStart"] = new StateStart(*this, world);
    _states["StateFinished"] = new StateFinished(*this);
    _states["StateWoodcutting"] = new StateWoodcutting(*this, world);
}

StateManager::StateManager(ScriptManager& scriptManager, World& world):
    _scriptManager(scriptManager)
{
    registerStates(world);
    g_stateManager = this;
}

State *StateManager::getState(const std::string &name) {
    return _states[name];
}

void StateManager::registerScriptedStates() {
    path p("scripts/states/");

    for (auto it = directory_iterator(p); it != directory_iterator(); it++) {
        _scriptManager.loadScript(it->path().string());
    }
}

void StateManager::registerScriptedState(char const *tableName, char const *stateName) {
    ScriptedState* state = new ScriptedState(*this, _scriptManager, tableName);
    _states[stateName] = state;
}
