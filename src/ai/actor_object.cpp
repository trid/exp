#include "actor_object.h"

#include "actor.h"
#include "constants.h"

ActorObject::ActorObject(Actor *actor) {
    Core::CallbackParameter<int, Actor>* maxFeed = new Core::CallbackParameter<int, Actor>(actor);
    Core::CallbackParameter<int, Actor>* maxWater = new Core::CallbackParameter<int, Actor>(actor);

    maxFeed->setSetterFunction(&Actor::setMaxFood);
    maxFeed->setGetterFunction(&Actor::getMaxFood);

    maxWater->setSetterFunction(&Actor::setMaxWater);
    maxWater->setGetterFunction(&Actor::getMaxWater);

    addParameter(kMaxFoodParameter, Core::ParameterPtr(maxFeed));
    addParameter(kMaxWaterParameter, Core::ParameterPtr(maxWater));
}
