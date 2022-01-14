//
// Created by TriD on 18.10.2021.
//

#include "actor.h"

namespace Core::AI::Agents {

void Actor::removeStatus(const std::string& stateName) {
    _statuses.erase(stateName);
}

void Actor::setBehaviourStep(BehaviourStepOpt step) {
    _step = std::move(step);
    if (!_step) {
        _executingReaction = false;
    }
}

void Actor::addStatus(const std::string& stateName) {
    _statuses.insert(stateName);
}

void Actor::setReactor(const std::string& stateName, const std::string& reactionState) {
    _statusReactors[stateName] = reactionState;
}

void Actor::setAction(Core::Actions::ActionPtr action) {
    if (_currentAction) {
        _currentAction->stop();
    }
    _currentAction = action;
}

void Actor::removeAction() {
    if (_currentAction) {
        _currentAction->stop();
        _currentAction = nullptr;
    }
}

bool Actor::hasAction() const {
    return _currentAction != nullptr;
}

BehaviourStepOpt Actor::getBehaviourStep() { return _step; }

const std::unordered_set<std::string>& Actor::getStatuses() const {
    return _statuses;
}

bool Actor::isExecutingReaction() const {
    return _executingReaction;
}

const std::unordered_map<std::string, std::string>& Actor::getStatusReactors() const {
    return _statusReactors;
}

void Actor::setExecutingReaction(bool executingReaction) {
    _executingReaction = executingReaction;
}

}