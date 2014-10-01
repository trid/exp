#include "lua.hpp"

int print(lua_State* state);
int registerScriptedState(lua_State* state);

//Actors
int setState(lua_State* state);
int updateSteps(lua_State* state);
int resetSteps(lua_State* state);
int getSteps(lua_State* state);
int addFood(lua_State* state);
int getPlace(lua_State* state);
int moveTo(lua_State* state);
int getThirsty(lua_State* state);
int drink(lua_State* state);
int sendTo(lua_State* state);
int eat(lua_State* state);
int getFeed(lua_State* state);

//Messages
int getMessageType(lua_State* state);

//World
int getStoredFood(lua_State* state);