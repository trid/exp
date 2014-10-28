#include "actor.h"
#include "scripted_state.h"
#include "../script_manager.h"

void ScriptedState::callFunction(Actor *actor, const string &function) {
    lua_State* state = ScriptManager::getInstance().getState();
    lua_getglobal(state, tableName.c_str());
    lua_pushstring(state, function.c_str());
    lua_gettable(state, -2);
    if (lua_isfunction(state, -1)) {
        lua_remove(state, -2);
        lua_pushlightuserdata(state, actor);
        lua_call(state, 1, 0);
    }
}

void ScriptedState::execute(Actor *actor) {
    callFunction(actor, "execute");
}

void ScriptedState::exit(Actor *actor) {
    callFunction(actor, "exit");
}

void ScriptedState::enter(Actor *actor) {
    callFunction(actor, "enter");
}

ScriptedState::ScriptedState(const string &tableName): tableName(tableName) {

}

void ScriptedState::processMessage(Actor *actor, Message &message) {
    lua_State* state = ScriptManager::getInstance().getState();
    lua_getglobal(state, tableName.c_str());
    lua_pushstring(state, "processMessage");
    lua_gettable(state, -2);
    if (lua_isfunction(state, -1)) {
        lua_remove(state, -2);
        lua_pushlightuserdata(state, actor);
        lua_pushlightuserdata(state, &message);
        lua_call(state, 2, 0);
    }
}
