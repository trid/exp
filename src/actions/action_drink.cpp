#include "action_drink.h"

#include "../ai/actor.h"

bool ActionDrink::isValid() {
    return actor->getPosition() == "well";
}

void ActionDrink::update(int delta) {
    time += delta;
    if (time >= maxTime) {
        time = maxTime;
        actor->setWater(actor->getMaxWater());
        actor->removeGlobalState("thirsty");
        actor->say("Ooh! Not thirsty anymore!");
    }
}

int ActionDrink::progress() {
    return time * 100 / maxTime;
}

bool ActionDrink::isFinished() {
    return time >= maxTime;
}

ActionDrink::ActionDrink(Actor* actor, World& world):
    Action(actor, world) {}
