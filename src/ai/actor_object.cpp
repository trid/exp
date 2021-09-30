#include "actor_object.h"

#include "actor.h"
#include "constants.h"

ActorObject::ActorObject(Actor *actor) {
    CallbackParameter<int, Actor>* maxFeed = new CallbackParameter<int, Actor>(actor);
    CallbackParameter<int, Actor>* maxWater = new CallbackParameter<int, Actor>(actor);

    maxFeed->setSetterFunction(&Actor::setMaxFood);
    maxFeed->setGetterFunction(&Actor::getMaxFood);

    maxWater->setSetterFunction(&Actor::setMaxWater);
    maxWater->setGetterFunction(&Actor::getMaxWater);

    addParameter(kMaxFoodParameter, ParameterPtr(maxFeed));
    addParameter(kMaxWaterParameter, ParameterPtr(maxWater));
}
