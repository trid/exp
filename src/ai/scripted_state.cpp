#include "scripted_state.h"

#include "lua5.1/lua.hpp"

#include "../scripting/script_context.h"

#include "actor.h"
#include "constants.h"


void ScriptedState::callFunction(Actor *actor, const string &function) {
    _scriptContext.callFunctionInTable(_tableName, function, {actor});
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

ScriptedState::ScriptedState(StateManager& stateManager, ScriptContext& scriptManager, const string& tableName) :
        State(stateManager),
        _scriptContext(scriptManager),
        _tableName(tableName) {

}

void ScriptedState::processMessage(Actor *actor, Message &message) {
    _scriptContext.callFunctionInTable(_tableName, kScriptProcessMessageMethodName, {actor, &message});
}
