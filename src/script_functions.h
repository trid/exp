#include "lua.hpp"

int print(lua_State* state);
int registerScriptedState(lua_State* state);
int setState(lua_State* state);
int updateSteps(lua_State* state);
int resetSteps(lua_State* state);
int getSteps(lua_State* state);
int addFood(lua_State* state);
int moveTo(lua_State* state);
int getThirsty(lua_State* state);
int drink(lua_State* state);