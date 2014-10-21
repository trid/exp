#include "lua.hpp"

//Utils
int print(lua_State* state);
int registerScriptedState(lua_State* state);

//Actors
int setState(lua_State* state);
int addFood(lua_State* state);
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

//Messages
int getMessageType(lua_State* state);

//World
int getStoredFood(lua_State* state);

//Actors registry
int createActor(lua_State* state);

//Scene objects
int createSceneObject(lua_State* state);