#include "../scripting/script_object.h"
#include "actor.h"

namespace Core::AI {

class ActorObject : public ScriptObject {
public:
    ActorObject(Actor* actor);
};

} // namespace Core::AI