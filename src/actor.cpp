#include "actor.h"

#include "state.h"
#include "world.h"
#include "view/view.h"
#include "view/scene_object_manager.h"

#include <iostream>

using std::cout;
using std::endl;

void Actor::update() {
    if (food > 0) {
        food--;
    }
    else {
        addGlobalState("thirsty");
    }
    if (water > 0) {
        water--;
    }
    else {
        addGlobalState("hungry");
    }

    if (!globalStates.empty() && isStateBreackable()) {
        State* reactionState;
        for (auto globalState: globalStates) {
            reactionState = globalStateReactors[globalState];
            if (reactionState) {
                setState(reactionState);
                break;
            }
        }
    }

    if (!state) {
        setState(globalStateReactors["NoState"]);
    }

    if (state) {
        state->execute(this);
    }
}

void Actor::eat() {
    if (position == "home") {
        food = 90;
        World::getWorld().removeFood();
    }
    else {
        say("I'm not at home, there is nothing to eat");
    }
}

void Actor::drink() {
    if (position == "well") {
        water = 60;
    }
    else {
        say("There is no water to drink");
    }
}

void Actor::setState(State* state) {
    if (this->state) {
        this->state->exit(this);
    }
    state->enter(this);
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
    MapObjectPtr mapObject = SceneObjectManager::getInstance().getMapObject(position);
    x = mapObject->getX();
    y = mapObject->getY();
}

void Actor::addGlobalState(const string &stateName) {
    globalStates.insert(stateName);
    if (executingState == "" && isStateBreackable()) {
        State* reaction = globalStateReactors[stateName];
        if (reaction) {
            executingState = stateName;
        }
    }
}

void Actor::setReactor(const string &stateName, State *reactionState) {
    globalStateReactors[stateName] = reactionState;
}
