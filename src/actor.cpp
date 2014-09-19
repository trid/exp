#include "actor.h"
#include "state_start.h"

Actor::Actor() {
    state = StateStart::getInstance();
}

void Actor::update() {
    if (food > 0) food--;
    if (water > 0) water--;
}

void Actor::eat() {
    food = 90;
}

void Actor::drink() {
    water = 60;
}

void Actor::setState(State* state) {
    this->state->exit(this);
    state->enter(this);
    this->state = state;
}