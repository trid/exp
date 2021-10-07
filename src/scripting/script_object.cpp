#include "../parameter.h"
#include "script_object.h"


void ScriptObject::addParameter(string const &name, Core::ParameterPtr ptr) {
    parameters[name] = ptr;
}

Core::ParameterPtr ScriptObject::getParameter(const string &name) {
    return parameters[name];
}


void ScriptObject::deleteParameter(const string &name) {
    parameters[name] = nullptr;
}
