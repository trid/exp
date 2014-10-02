#include "actor.h"

#include "state.h"
#include "world.h"

#include <iostream>

using std::cout;
using std::endl;

void Actor::update() {
    if (food > 0) food--;
    if (water > 0) water--;
    if (state) {
        state->execute(this);
    }
}

void Actor::eat() {
    food = 90;
    World::getWorld().removeFood();
}

void Actor::drink() {
    water = 60;
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

int Actor::getSteps() {
    return steps;
}

void Actor::processMessage(Message &message) {
    if (state) {
        state->processMessage(this, message);
    }
}

void Actor::say(const string &message) {
    cout << name << ": " << message << endl;
}
