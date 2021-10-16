#include "actor.h"

#include <iostream>

#include "../constants.h"
#include "../world.h"
#include "../actions/constants.h"
#include "../view/view_facade.h"
#include "../view/widgets/gui_panel.h"

#include "constants.h"
#include "behaviour_step.h"

extern View::Widgets::GUIPanel* g_panel;

namespace Core::AI {

void Actor::update() {

}

void Actor::updateStatus() {
    if (food > 0) {
        food--;
    } else {
        addStatus(kHungryStateName);
    }
    if (water > 0) {
        water--;
    } else {
        addStatus(kThirstyStateName);
    }
}

void Actor::eat() {
    _world.doAction(this, Core::Actions::kActionEat);
}

void Actor::drink() {
    _world.doAction(this, Core::Actions::kActionDrink);
}

void Actor::removeStatus(const string& stateName) {
    _statuses.erase(stateName);
}

void Actor::setBehaviourStep(BehaviourStepOpt step) {
    _step = step;
    if (!step) {
        _executingReaction = false;
    }
}

void Actor::setTargetPosition(const string& position) {
    target = position;
}

const string& Actor::getTargetPosition() {
    return target;
}

void Actor::processMessage(Core::Message& message) {

}

void Actor::say(const string& message) {
    std::cout << name << ": " << message << std::endl;
    g_panel->addMessage(name + ": " + message);
}

void Actor::addItem() {
    if (inventory < inventoryLimit) {
        inventory++;
    }
}

void Actor::unloadWood() {
    _world.addWood(inventory);
    inventory = 0;
}

void Actor::unloadFood() {
    _world.addFood(inventory);
    inventory = 0;
}

int Actor::getInventoryLimit() {
    return inventoryLimit;
}

void Actor::setPosition(const string& position) {
    this->position = position;
    if (position != Core::kPositionInRoute) {
        const auto mapObject = _world.getWorldMap().getLocation(position);
        x = mapObject->getXPos();
        y = mapObject->getYPos();
    }
}

void Actor::addStatus(const string& stateName) {
    _statuses.insert(stateName);
}

void Actor::setReactor(const string& stateName, const string& reactionState) {
    _statusReactors[stateName] = reactionState;
}

void Actor::setAction(Core::Actions::ActionPtr& action) {
    if (currentAction) {
        currentAction->stop();
    }
    currentAction = action;
}

void Actor::removeAction() {
    if (currentAction) {
        currentAction->stop();
        currentAction = nullptr;
    }
}

bool Actor::hasAction() {
    return currentAction != nullptr;
}

Actor::Actor(View::ViewFacade& view, Core::World& world, View::Widgets::GUIPanel& guiPanel) :
        _view(view),
        _world(world),
        _guiPanel(guiPanel) {}

BehaviourStepOpt Actor::getBehaviourStep() { return _step; }

const std::unordered_set<std::string>& Actor::getStatuses() {
    return _statuses;
}

bool Actor::isExecutingReaction() {
    return _executingReaction;
}

const std::unordered_map<std::string, std::string>& Actor::getStatusReactors() {
    return _statusReactors;
}

void Actor::setExecutingReaction(bool executingReaction) {
    _executingReaction = executingReaction;
}

} // namespace Core::AI