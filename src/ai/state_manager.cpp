#include "state_manager.h"

#include "../scripting/script_context.h"

#include "constants.h"
#include "scripted_state.h"
#include "state_finished.h"
#include "state_start.h"
#include "state_woodcutting.h"


namespace Core::AI {

StateManager::StateManager(Core::World& world) {
    registerStates(world);
}

void StateManager::registerStates(Core::World& world) {
    _states[kStateStartName] = std::make_unique<StateStart>(*this, world);
    _states[kStateFinishedName] = std::make_unique<StateFinished>(*this);
    _states[kStateWoodcuttingName] = std::make_unique<StateWoodcutting>(*this, world);
}

StateOpt StateManager::getState(const std::string& name) {
    auto it = _states.find(name);
    if (it != _states.end()) {
        return *it->second;
    }
    return boost::none;
}

void StateManager::registerScriptedState(const std::string& tableName, const std::string& stateName,
                                         Scripting::ScriptContext& scriptContext) {
    _states[stateName] = std::make_unique<ScriptedState>(*this, scriptContext, tableName);
}

} // namespace Core::AI