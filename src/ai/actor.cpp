#include "actor.h"

#include "state.h"
#include "../world.h"
#include "../view/view.h"
#include "../view/scene_object_manager.h"

#include <iostream>

using std::cout;
using std::endl;

void Actor::update() {
    if (!globalStates.empty() && isStateBreackable() && executingState == "") {
        State* reactionState;
        for (auto globalState: globalStates) {
            reactionState = globalStateReactors[globalState];
            if (reactionState) {
                executingState = globalState;
                setState(reactionState);
                break;
            }
        }
    }

    if (!state) {
        setState(globalStateReactors["NoState"]);
    }
    else {
        state->execute(this);
    }
}

void Actor::updateStatus() {
    if (food > 0) {
        food--;
    }
    else {
        addGlobalState("hungry");
    }
    if (water > 0) {
        water--;
    }
    else {
        addGlobalState("thirsty");
    }
}

void Actor::eat() {
    World::getWorld().doAction(this, "eat");
}

void Actor::drink() {
    World::getWorld().doAction(this, "drink");
}

void Actor::removeGlobalState(const string &stateName) {
    globalStates.erase(stateName);
    if (executingState == stateName) {
        executingState = "";
    }
}

void Actor::setState(State* state) {
    if (this->state) {
        this->state->exit(this);
    }
    if (state) {
        state->enter(this);
    }
    this->state = state;
}

void Actor::setTargetPosition(const string& position) {
    target = position;
}

const string& Actor::getTargetPosition() {
    return target;
}

void Actor::processMessage(Message &message) {
    if (state) {
        state->processMessage(this, message);
    }
}

void Actor::say(const string &message) {
    cout << name << ": " << message << endl;
    View::getView().addMessage(name + ": " + message);
}

void Actor::addItem() {
    if (inventory < inventoryLimit) {
        inventory++;
    }
}

void Actor::unloadWood() {
    World::getWorld().addWood(inventory);
    inventory = 0;
}

void Actor::unloadFood() {
    World::getWorld().addFood(inventory);
    inventory = 0;
}

int Actor::getInventoryLimit() {
    return inventoryLimit;
}

void Actor::setPosition(const string &position) {
    this->position = position;
    if (position != "In route") {
        MapObjectPtr mapObject = SceneObjectManager::getInstance().getMapObject(position);
        x = mapObject->getX();
        y = mapObject->getY();
    }
}

void Actor::addGlobalState(const string &stateName) {
    globalStates.insert(stateName);
    if (executingState == "" && isStateBreackable()) {
        State* reaction = globalStateReactors[stateName];
        if (reaction) {
            executingState = stateName;
            setState(reaction);
        }
    }
}

void Actor::setReactor(const string &stateName, State *reactionState) {
    globalStateReactors[stateName] = reactionState;
}

void Actor::setAction(ActionPtr &action) {
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
