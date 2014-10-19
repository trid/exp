#include <lua.hpp>
#include <iostream>
#include "script_functions.h"
#include "state_manager.h"
#include "world.h"
#include "registry.h"
#include "view/view.h"
#include "view/scene_object_manager.h"

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

    State *actorState = StateManager::getInstance().getState(stateName);
    actor->setState(actorState);
    return 0;
}

int addFood(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    if (actor->getPosition() == "forest") {
        actor->addItem();
    }
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
    Actor* actor = (Actor*)lua_topointer(state, -2);
    const char* direction = lua_tostring(state, -1);

    World::getWorld().moveActor(actor, direction);

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

int say(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -2);
    const char* message = lua_tostring(state, -1);

    actor->say(message);
}

int setName(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -2);
    const char* name = lua_tostring(state, -1);

    actor->setName(name);
}

int getInventory(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    lua_pushinteger(state, actor->getInventory());

    return 1;
}

int getInventorySize(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    lua_pushinteger(state, actor->getInventoryLimit());

    return 1;
}

int unloadWood(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    actor->unloadWood();

    return 0;
}

int unloadFood(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    actor->unloadFood();

    return 0;
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

//Actor registry
int createActor(lua_State* state) {
    Actor& actor = ActorsRegistry::getRegistry().createActor();
    lua_pushlightuserdata(state, &actor);

    return 1;
}

//Scene objects
int createSceneObject(lua_State* state) {
    int x, y;
    const char* path;
    const char* name;
    x = lua_tointeger(state, -4);
    y = lua_tointeger(state, -3);
    path = lua_tostring(state, -2);
    name = lua_tostring(state, -1);

    SceneObjectManager::getInstance().createMapObject(x, y, path, name);

    return 0;
}