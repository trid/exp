#include "lua5.1/lua.hpp"
#include "../ai/state_manager.h"

namespace Scripting {

//Utils
int print(lua_State* state);
int registerScriptedState(lua_State* state);

//Actors
int setState(lua_State* state);
int getPlace(lua_State* state);
int moveTo(lua_State* state);
int getThirsty(lua_State* state);
int drink(lua_State* state);
int sendTo(lua_State* state);
int eat(lua_State* state);
int getFeed(lua_State* state);
int say(lua_State* state);
int setName(lua_State* state);
int getInventory(lua_State* state);
int getInventorySize(lua_State* state);
int unloadWood(lua_State* state);
int unloadFood(lua_State* state);
int setReaction(lua_State* state);
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
int createActor(lua_State* state);

//Scene objects
int createSceneObject(lua_State* state);

//Script objects
int getScriptObject(lua_State* state);
int getObjectParameter(lua_State* state);
int setParameterValue(lua_State* state);
int getParameterValue(lua_State* state);

} // namespace Scripting