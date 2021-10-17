#include "agent.h"

#include <iostream>

#include "../../constants.h"
#include "../../world.h"
#include "../../actions/constants.h"
#include "../../view/view_facade.h"
#include "../../view/widgets/gui_panel.h"

#include "../constants.h"
#include "../behaviour_step.h"

extern View::Widgets::GUIPanel* g_panel;

namespace Core::AI::Actors {

Agent::Agent(int id, Core::World& world, View::Widgets::GUIPanel& guiPanel) :
        id(id),
        _world(world),
        _guiPanel(guiPanel) {}

void Agent::removeStatus(const string& stateName) {
    _statuses.erase(stateName);
}

void Agent::setBehaviourStep(BehaviourStepOpt step) {
    _step = step;
    if (!step) {
        _executingReaction = false;
    }
}

void Agent::processMessage(Core::Message& message) {

}

void Agent::say(const string& message) {
    std::cout << name << ": " << message << std::endl;
    g_panel->addMessage(name + ": " + message);
}

void Agent::addItem() {
    if (inventory < inventoryLimit) {
        inventory++;
    }
}

void Agent::unloadWood() {
    _world.addWood(inventory);
    inventory = 0;
}

void Agent::unloadFood() {
    _world.addFood(inventory);
    inventory = 0;
}

int Agent::getInventoryLimit() {
    return inventoryLimit;
}

void Agent::addStatus(const string& stateName) {
    _statuses.insert(stateName);
}

void Agent::setReactor(const string& stateName, const string& reactionState) {
    _statusReactors[stateName] = reactionState;
}

void Agent::setAction(Core::Actions::ActionPtr& action) {
    if (currentAction) {
        currentAction->stop();
    }
    currentAction = action;
}

void Agent::removeAction() {
    if (currentAction) {
        currentAction->stop();
        currentAction = nullptr;
    }
}

bool Agent::hasAction() {
    return currentAction != nullptr;
}

BehaviourStepOpt Agent::getBehaviourStep() { return _step; }

const std::unordered_set<std::string>& Agent::getStatuses() {
    return _statuses;
}

bool Agent::isExecutingReaction() {
    return _executingReaction;
}

const std::unordered_map<std::string, std::string>& Agent::getStatusReactors() {
    return _statusReactors;
}

void Agent::setExecutingReaction(bool executingReaction) {
    _executingReaction = executingReaction;
}

} // namespace Core::AI::Actors