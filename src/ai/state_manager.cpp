#include "state_manager.h"

#include <boost/filesystem.hpp>

#include "../scripting/script_context.h"

#include "constants.h"
#include "scripted_state.h"
#include "state_finished.h"
#include "state_start.h"
#include "state_woodcutting.h"

extern StateManager* g_stateManager;

using boost::filesystem::path;
using boost::filesystem::directory_iterator;
using boost::filesystem::directory_entry;

void StateManager::registerStates(Core::World& world) {
    _states[kStateStartName] = std::make_unique<StateStart>(*this, world);
    _states[kStateFinishedName] = std::make_unique<StateFinished>(*this);
    _states[kStateWoodcuttingName] = std::make_unique<StateWoodcutting>(*this, world);
}

StateManager::StateManager(ScriptContext& scriptManager, Core::World& world):
    _scriptManager(scriptManager)
{
    registerStates(world);
    g_stateManager = this;
}

StateOpt StateManager::getState(const std::string &name) {
    auto it = _states.find(name);
    if (it != _states.end()) {
        return *it->second;
    }
    return boost::none;
}

void StateManager::registerScriptedStates() {
    path p(kStateScriptsPath);

    for (auto it = directory_iterator(p); it != directory_iterator(); it++) {
        _scriptManager.loadScript(it->path().string());
    }
}

void StateManager::registerScriptedState(char const *tableName, char const *stateName) {
    _states[stateName] = std::make_unique<ScriptedState>(*this, _scriptManager, tableName);
}
