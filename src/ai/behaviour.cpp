//
// Created by TriD on 13.10.2021.
//

#include "behaviour.h"

namespace Core::AI {

Behaviour::Behaviour(const std::string& name, const sol::table& startingStep) : _name(name),
                                                                                _startingStep(startingStep) {}

BehaviourStep Behaviour::getStartingStep() {
    return BehaviourStep(_startingStep);
}

} // namespace Core::AI