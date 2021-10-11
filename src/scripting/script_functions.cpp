#include "script_functions.h"

#include <iostream>

#include "lua.hpp"

#include "../constants.h"
#include "../location_manager.h"
#include "../world.h"

#include "../ai/actor_object.h"
#include "../ai/state_manager.h"
#include "../ai/registry.h"

#include "../view/scene_object_manager.h"
#include "../view/view_facade.h"

#include "constants.h"
#include "script_object_manager.h"


View::ViewFacade* g_view = nullptr;
View::SceneObjectManager* g_sceneObjectManager = nullptr;
extern Core::World* g_world;
View::Widgets::GUIPanel* g_panel;

namespace Scripting {

void print(const std::string& message) {
    std::cout << kScriptMessagePrefix << message;
}

void setState(Core::AI::Actor& actor, const std::string& stateName, Core::AI::StateManager& stateManager) {
    if (stateName.empty()) {
        actor.setState(boost::none);
    } else {
        auto actorState = stateManager.getState(stateName);
        actor.setState(actorState);
    }
}

int getThirsty(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    int water = actor->getWater();
    lua_pushinteger(state, water);
    return 1;
}

int drink(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    actor->drink();
    return 0;
}

int getPlace(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    const string& place = actor->getPosition();
    lua_pushstring(state, place.c_str());

    return 1;
}

int eat(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    actor->eat();

    return 0;
}

int getFeed(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    lua_pushinteger(state, actor->getFood());

    return 1;
}

int getInventory(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    lua_pushinteger(state, actor->getInventory());

    return 1;
}

int getInventorySize(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    lua_pushinteger(state, actor->getInventoryLimit());

    return 1;
}

int unloadWood(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    actor->unloadWood();

    return 0;
}

int unloadFood(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    actor->unloadFood();

    return 0;
}

void setReaction(Core::AI::Actor& actor, const std::string& reactionType, const std::string& stateName, Core::AI::StateManager& stateManager) {
    actor.setReactor(reactionType, stateManager.getState(stateName));
}

int setStateBreackable(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -2);
    bool breackable = (bool) lua_toboolean(state, -1);
    actor->setStateBreackable(breackable);

    return 1;
}

int hasAction(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    bool hasAction = actor->hasAction();
    lua_pushboolean(state, hasAction);

    return 1;
}

int doAction(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -2);
    const char* action = lua_tostring(state, -1);

    g_world->doAction(actor, action);
    return 0;
}

int getId(lua_State* state) {
    auto* actor = (Core::AI::Actor*) lua_topointer(state, -1);
    lua_pushinteger(state, actor->getID());

    return 1;
}

// Messages

int getMessageType(lua_State* state) {
    Core::Message* message = (Core::Message*) lua_topointer(state, -1);
    char const* messageType = message->messageType.c_str();
    lua_pushstring(state, messageType);

    return 1;
}

// World
int getStoredFood(lua_State* state) {
    lua_pushinteger(state, g_world->getFood());

    return 1;
}

int getStoredWood(lua_State* state) {
    lua_pushinteger(state, g_world->getWood());

    return 1;
}

//Actor registry
Core::AI::Actor& createActor(Core::AI::ActorsRegistry& actorsRegistry) {
    return actorsRegistry.createActor(*g_view, *g_world, *g_panel);
}

//Scene objects
int createSceneObject(lua_State* state) {
    int x, y;
    const char* name;
    const char* type;
    x = lua_tointeger(state, -4);
    y = lua_tointeger(state, -3);
    type = lua_tostring(state, -2);
    name = lua_tostring(state, -1);

    g_world->getLocationManager().createLocation(type, name, x, y, *g_sceneObjectManager);

    return 0;
}

} // namespace Scripting