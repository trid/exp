#include "action_drink.h"

#include "../ai/constants.h"
#include "../ai/actor.h"

#include "constants.h"

bool ActionDrink::isValid() {
    return actor->getPosition() == kWellLocationName;
}

void ActionDrink::update(int delta) {
    time += delta;
    if (time >= maxTime) {
        time = maxTime;
        actor->setWater(actor->getMaxWater());
        actor->removeGlobalState(kThirstyStateName);
        actor->say(kActionDrinkExecutedMessage);
    }
}

int ActionDrink::progress() {
    return time * 100 / maxTime;
}

bool ActionDrink::isFinished() {
    return time >= maxTime;
}

ActionDrink::ActionDrink(Actor* actor, Core::World& world):
    Action(actor, world),
    maxTime(kActionDrinkTime) {}
