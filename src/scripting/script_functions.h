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
int getPlace(lua_State* state);
int getThirsty(lua_State* state);
int drink(lua_State* state);
int eat(lua_State* state);
int getFeed(lua_State* state);
int getInventory(lua_State* state);
int getInventorySize(lua_State* state);
int unloadWood(lua_State* state);
int unloadFood(lua_State* state);
void setReaction(Core::AI::Actor& actor, const std::string& reactionType, const std::string& stateName, Core::AI::StateManager& stateManager);
int setStateBreackable(lua_State* state);
int hasAction(lua_State* state);
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