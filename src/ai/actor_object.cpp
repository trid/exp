#include "actor.h"
#include "actor_object.h"

ActorObject::ActorObject(Actor *actor) {
    CallbackParameter<int, Actor>* maxFeed = new CallbackParameter<int, Actor>(actor);
    CallbackParameter<int, Actor>* maxWater = new CallbackParameter<int, Actor>(actor);

    maxFeed->setSetterFunction(&Actor::setMaxFood);
    maxFeed->setGetterFunction(&Actor::getMaxFood);

    maxWater->setSetterFunction(&Actor::setMaxWater);
    maxWater->setGetterFunction(&Actor::getMaxWater);

    addParameter("maxFood", ParameterPtr(maxFeed));
    addParameter("maxWater", ParameterPtr(maxWater));
}
