#include "actor.h"
#include "actor_object.h"

ActorObject::ActorObject(Actor *actor) {
    CallbackParameter<int, Actor>* maxFeed = new CallbackParameter<int, Actor>(actor);
    CallbackParameter<int, Actor>* maxWater = new CallbackParameter<int, Actor>(actor);

    addParameter("maxFeed", maxFeed);
    addParameter("maxWater", maxWater);
}
