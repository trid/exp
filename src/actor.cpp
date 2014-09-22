#include "actor.h"


void Actor::update() {
    if (food > 0) food--;
    if (water > 0) water--;
    if (state) {
        state->execute(this);
    }
}

void Actor::eat() {
    food = 90;
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

void Actor::setTargetPosition(Position position) {
    target = position;
}

Position Actor::getTargetPosition() {
    return target;
}

int Actor::getSteps() {
    return steps;
}

