#include "parameter.h"
#include "script_object.h"


void ScriptObject::addParameter(string name, ParameterPtr ptr) {
    parameters[name] = ptr;
}

AbstractParameter & ScriptObject::getParameter(const string &name) {
    return *parameters[name];
}


void ScriptObject::deleteParameter(const string &name) {
    parameters[name] = nullptr;
}