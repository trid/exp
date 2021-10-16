#include "lua.hpp"
#include "../ai/state_manager.h"

namespace Core::AI::Actors {
class ActorsRegistry;
}

namespace Scripting {

// Utils
void print(const std::string& message);

// Actors
void setState(Core::AI::Actors::Actor& actor, const std::string& stateName, Core::AI::StateManager& stateManager);
void setReaction(Core::AI::Actors::Actor& actor, const std::string& reactionType, const std::string& behaviourName);
int getId(lua_State* state);

// Actors registry
Core::AI::Actors::Actor& createActor(Core::AI::Actors::ActorsRegistry& actorsRegistry, Core::World& world);

// Locations
void createSceneObject(const std::string& type, const std::string& name, int x, int y, Core::World& world);

} // namespace Scripting