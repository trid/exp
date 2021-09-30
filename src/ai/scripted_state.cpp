#include "scripted_state.h"

#include "lua5.1/lua.hpp"

#include "../script_manager.h"

#include "actor.h"
#include "constants.h"


void ScriptedState::callFunction(Actor *actor, const string &function) {
    lua_State* state = _scriptManager.getState();
    lua_getglobal(state, _tableName.c_str());
    lua_pushstring(state, function.c_str());
    lua_gettable(state, -2);
    if (lua_isfunction(state, -1)) {
        lua_remove(state, -2);
        lua_pushlightuserdata(state, actor);
        lua_call(state, 1, 0);
    }
}

void ScriptedState::execute(Actor *actor) {
    callFunction(actor, kScriptExecuteMethodName);
}

void ScriptedState::exit(Actor *actor) {
    callFunction(actor, kScriptExitMethodName);
}

void ScriptedState::enter(Actor *actor) {
    callFunction(actor, kScriptEnterMethodName);
}

ScriptedState::ScriptedState(StateManager& stateManager, ScriptManager& scriptManager, const string& tableName) :
    State(stateManager),
    _scriptManager(scriptManager),
    _tableName(tableName) {

}

void ScriptedState::processMessage(Actor *actor, Message &message) {
    lua_State* state = _scriptManager.getState();
    lua_getglobal(state, _tableName.c_str());
    lua_pushstring(state, kScriptProcessMessageMethodName);
    lua_gettable(state, -2);
    if (lua_isfunction(state, -1)) {
        lua_remove(state, -2);
        lua_pushlightuserdata(state, actor);
        lua_pushlightuserdata(state, &message);
        lua_call(state, 2, 0);
    }
}
