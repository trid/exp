#include "state_manager.h"

namespace Core::AI {

StateManager::StateManager(Core::World& world) {
}

BehaviourOpt StateManager::getBehaviour(const std::string& name) {
    auto it = _behaviours.find(name);
    if (it != _behaviours.end()) {
        return it->second;
    }
    return boost::none;
}

void StateManager::registerBehaviour(const std::string& behaviourName, const sol::table& startingStep) {
    assert(_behaviours.find(behaviourName) == _behaviours.end());
    _behaviours.emplace(behaviourName, std::move(Behaviour{behaviourName, startingStep}));
}

} // namespace Core::AI