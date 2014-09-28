#include <lua.hpp>
#include <iostream>
#include "script_functions.h"
#include "state_manager.h"
#include "world.h"

using std::cout;

int print(lua_State* state) {
    char const *str = lua_tostring(state, 1);
    cout << "LUA: " << str;
    return 0;
}

int registerScriptedState(lua_State* state) {
    const char* stateName = lua_tostring(state, -2);
    const char* tableName = lua_tostring(state, -1);

    StateManager::getInstance().registerScriptedState(tableName, stateName);
    return 0;
}

int setState(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -2);
    const char* stateName = lua_tostring(state, -1);

    actor->setState(StateManager::getInstance().getState(stateName));
    return 0;
}

int updateSteps(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    actor->updateSteps();
    return 0;
}

int resetSteps(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    actor->resetSteps();
    return 0;
}

int getSteps(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    int steps = actor->getSteps();
    lua_pushinteger(state, steps);
    return 1;
}

int addFood(lua_State* state) {
    World::getWorld().addFood();
    return 0;
}

int moveTo(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -2);
    const char* place = lua_tostring(state, -1);
    actor->setPosition(place);
    return 0;
}

int getThirsty(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    int water = actor->getWater();
    lua_pushinteger(state, water);
    return 1;
}

int drink(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    actor->drink();
    return 0;
}