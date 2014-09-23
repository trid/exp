#include "state_manager.h"
#include "state_start.h"
#include "state_finished.h"
#include "state_moving.h"
#include "state_woodcutting.h"

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
