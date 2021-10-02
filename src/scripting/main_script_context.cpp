//
// Created by TriD on 02.10.2021.
//

#include "main_script_context.h"

#include "script_functions.h"

MainScriptContext::MainScriptContext():
    ScriptContext()
{
    registerFunctions();
}

void MainScriptContext::registerFunctions() {
    registerFunction("print", print);
    registerFunction("registerScriptedState", registerScriptedState);
    registerFunction("setState", setState);
    registerFunction("moveTo", moveTo);
    registerFunction("getThirsty", getThirsty);
    registerFunction("drink", drink);
    registerFunction("getPlace", getPlace);
    registerFunction("sendTo", sendTo);
    registerFunction("eat", eat);
    registerFunction("getFeed", getFeed);
    registerFunction("say", say);
    registerFunction("setName", setName);
    registerFunction("getInventory", getInventory);
    registerFunction("getInventorySize", getInventorySize);
    registerFunction("unloadWood", unloadWood);
    registerFunction("unloadFood", unloadFood);
    registerFunction("setReaction", setReaction);
    registerFunction("setStateBreackable", setStateBreackable);
    registerFunction("hasAction", hasAction);
    registerFunction("doAction", doAction);
    registerFunction("getId", getId);

    registerFunction("getMessageType", getMessageType);

    registerFunction("getStoredFood", getStoredFood);
    registerFunction("getStoredWood", getStoredWood);

    registerFunction("createActor", createActor);

    registerFunction("createSceneObject", createSceneObject);

    registerFunction("getScriptObject", getScriptObject);
    registerFunction("getObjectParameter", getObjectParameter);
    registerFunction("setParameterValue", setParameterValue);
}
