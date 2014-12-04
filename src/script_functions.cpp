#include <lua.hpp>
#include <iostream>
#include "script_functions.h"
#include "ai/state_manager.h"
#include "world.h"
#include "ai/registry.h"
#include "view/view.h"
#include "view/scene_object_manager.h"
#include "script_object_manager.h"
#include "ai/actor_object.h"

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
    if (lua_isnil(state, -1)) {
        actor->setState(nullptr);
    }
    else {
        const char *stateName = lua_tostring(state, -1);

        State *actorState = StateManager::getInstance().getState(stateName);
        actor->setState(actorState);
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

int setReaction(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -3);
    const char* reactionName = lua_tostring(state, -2);
    const char* stateName = lua_tostring(state, -1);

    actor->setReactor(reactionName, StateManager::getInstance().getState(stateName));
}

int setStateBreackable(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -2);
    bool breackable = (bool) lua_toboolean(state, -1);
    actor->setStateBreackable(breackable);
}

int hasAction(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    bool hasAction = actor->hasAction();
    lua_pushboolean(state, hasAction);

    return 1;
}

int doAction(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -2);
    const char* action = lua_tostring(state, -1);

    World::getWorld().doAction(actor, action);
    return 0;
}

int getId(lua_State* state) {
    Actor* actor = (Actor*)lua_topointer(state, -1);
    lua_pushinteger(state, actor->getID());

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

int getStoredWood(lua_State* state) {
    lua_pushinteger(state, World::getWorld().getWood());

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

//Script objects
int getScriptObject(lua_State* state) {
    const char* name = lua_tostring(state, -1);
    lua_pushlightuserdata(state, ScriptObjectManager::getInstance().getItem(name));
    return 1;
}

int getObjectParameter(lua_State* state) {
    ActorObject* actorObject = (ActorObject*)lua_topointer(state, -2);
    const char* paramName = lua_tostring(state, -1);
    lua_pushlightuserdata(state, actorObject->getParameter(paramName).get());
    return 1;
}

int setParameterValue(lua_State* state) {
    AbstractParameter* parameter = (AbstractParameter *) lua_topointer(state, -2);
    if (lua_isnumber(state, -1)) {
        //Small trouble in LUA: it do not care about int or string convertible to int. Same with strings. Fuck.
        parameter->setData(lua_tointeger(state, -1));
        return 0;
    }
    if (lua_isstring(state, -1)) {
        parameter->setData(lua_tostring(state, -1));
        return 0;
    }
}

int getParameterValue(lua_State* state) {
    AbstractParameter* parameter = (AbstractParameter *) lua_topointer(state, -1);
    if (parameter->getType() == typeid(int)) {
        lua_pushinteger(state, parameter->getInt());
    }
    if (parameter->getType() == typeid(string)) {
        lua_pushstring(state, parameter->getString().c_str());
    }
    return 1;
}