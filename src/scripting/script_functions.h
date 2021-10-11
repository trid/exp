#include "lua.hpp"
#include "../ai/state_manager.h"

namespace Core::AI {
class ActorsRegistry;
}

namespace Scripting {

//Utils
void print(const std::string& message);

//Actors
void setState(Core::AI::Actor& actor, const std::string& stateName, Core::AI::StateManager& stateManager);
void setReaction(Core::AI::Actor& actor, const std::string& reactionType, const std::string& stateName, Core::AI::StateManager& stateManager);
int doAction(lua_State* state);
int getId(lua_State* state);

//Messages
int getMessageType(lua_State* state);

//World
int getStoredFood(lua_State* state);
int getStoredWood(lua_State* state);

//Actors registry
Core::AI::Actor& createActor(Core::AI::ActorsRegistry& actorsRegistry);

//Scene objects
int createSceneObject(lua_State* state);

} // namespace Scripting