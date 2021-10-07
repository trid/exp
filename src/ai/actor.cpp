#include "actor.h"

#include <iostream>

#include "../constants.h"
#include "../world.h"
#include "../actions/constants.h"
#include "../view/view_facade.h"
#include "../view/scene_object_manager.h"
#include "../view/widgets/gui_panel.h"

#include "constants.h"
#include "state.h"

namespace Core::AI {

void Actor::update() {
    if (!globalStates.empty() && isStateBreackable() && executingState == "") {
        StateOpt reactionState;
        for (auto globalState: globalStates) {
            reactionState = globalStateReactors[globalState];
            if (reactionState) {
                executingState = globalState;
                setState(reactionState);
                break;
            }
        }
    }

    if (!_state) {
        setState(globalStateReactors[kNoStateStateName]);
    } else {
        _state->execute(this);
    }
}

void Actor::updateStatus() {
    if (food > 0) {
        food--;
    } else {
        addGlobalState(kHungryStateName);
    }
    if (water > 0) {
        water--;
    } else {
        addGlobalState(kThirstyStateName);
    }
}

void Actor::eat() {
    _world.doAction(this, Core::Actions::kActionEat);
}

void Actor::drink() {
    _world.doAction(this, Core::Actions::kActionDrink);
}

void Actor::removeGlobalState(const string& stateName) {
    globalStates.erase(stateName);
    if (executingState == stateName) {
        executingState = "";
    }
}

void Actor::setState(const StateOpt& newState) {
    if (_state) {
        _state->exit(this);
    }
    if (newState) {
        newState->enter(this);
    }
    _state = newState;
}

void Actor::setTargetPosition(const string& position) {
    target = position;
}

const string& Actor::getTargetPosition() {
    return target;
}

void Actor::processMessage(Core::Message& message) {
    if (_state) {
        _state->processMessage(this, message);
    }
}

void Actor::say(const string& message) {
    std::cout << name << ": " << message << std::endl;
    _guiPanel.addMessage(name + ": " + message);
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
        View::MapObjectPtr mapObject = _world.getSceneObjectManager().getMapObject(position);
        x = mapObject->getX();
        y = mapObject->getY();
    }
}

void Actor::addGlobalState(const string& stateName) {
    globalStates.insert(stateName);
    if (executingState == "" && isStateBreackable()) {
        auto reaction = globalStateReactors[stateName];
        if (reaction) {
            executingState = stateName;
            setState(reaction);
        }
    }
}

void Actor::setReactor(const string& stateName, StateOpt reactionState) {
    globalStateReactors[stateName] = reactionState;
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

StateOpt Actor::getState() { return _state; }

} // namespace Core::AI