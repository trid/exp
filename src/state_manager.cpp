#include "state_manager.h"
#include "state_start.h"
#include "state_finished.h"
#include "state_moving.h"
#include "state_woodcutting.h"
#include "script_manager.h"
#include "scripted_state.h"

#include <boost/filesystem.hpp>

using boost::filesystem::path;
using boost::filesystem::directory_iterator;
using boost::filesystem::directory_entry;

void StateManager::registerStates() {
    states["StateStart"] = StateStart::getInstance();
    states["StateFinished"] = StateFinished::getInstance();
    states["StateMoving"] = StateMoving::getInstance();
    states["StateWoodcutting"] = StateWoodcutting::getInstance();
}

StateManager::StateManager() {
    registerStates();
}

State *StateManager::getState(const std::string &name) {
    return states[name];
}

void StateManager::registerScriptedStates() {
    path p("scripts/states/");

    for (auto it = directory_iterator(p); it != directory_iterator(); it++) {
        ScriptManager::getInstance().loadScript(it->path().string());
    }
}

void StateManager::registerScriptedState(char const *tableName, char const *stateName) {
    ScriptedState* state = new ScriptedState(tableName);
    states[stateName] = state;
}
