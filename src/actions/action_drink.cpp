#include "action_drink.h"

#include "../ai/constants.h"
#include "../ai/actors/actor.h"

#include "constants.h"

namespace Core::Actions {

bool ActionDrink::isValid() {
    return actor->getPosition() == kWellLocationName;
}

void ActionDrink::update(int delta) {
    time += delta;
    if (time >= maxTime) {
        time = maxTime;
        actor->setWater(actor->getMaxWater());
        actor->removeStatus(Core::AI::kThirstyStateName);
        actor->say(kActionDrinkExecutedMessage);
    }
}

int ActionDrink::progress() {
    return time * 100 / maxTime;
}

bool ActionDrink::isFinished() {
    return time >= maxTime;
}

ActionDrink::ActionDrink(AI::Actors::Actor* actor, Core::World& world) :
        Action(actor, world),
        maxTime(kActionDrinkTime) {}

} // namespace Core::Actions