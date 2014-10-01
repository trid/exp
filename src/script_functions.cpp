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

int getPlace(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    const string& place = actor->getPosition();
    lua_pushstring(state, place.c_str());

    return 1;
}

int sendTo(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -3);
    const char* direction = lua_tostring(state, -2);
    int steps = lua_tointeger(state, -1);

    World::getWorld().moveActor(actor, direction, steps);

    return 0;
}

int eat(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    actor->eat();

    return 0;
}

int getFeed(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    lua_pushinteger(state, actor->getFood());

    return 1;
}

// Messages

int getMessageType(lua_State* state) {
    Message* message = (Message*)lua_topointer(state, -1);
    char const *messageType = message->messageType.c_str();
    lua_pushstring(state, messageType);

    return 1;
}

// World
int getStoredFood(lua_State* state) {
    lua_pushinteger(state, World::getWorld().getFood());

    return 1;
}