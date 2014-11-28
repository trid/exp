#include "../script_object.h"
#include "actor.h"

class ActorObject: public ScriptObject {
public:
    ActorObject(Actor* actor);
};