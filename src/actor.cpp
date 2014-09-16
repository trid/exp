#include "actor.h"

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
