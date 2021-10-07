#include "../parameter.h"
#include "script_object.h"

namespace Scripting {

void ScriptObject::addParameter(std::string const& name, Core::ParameterPtr ptr) {
    parameters[name] = ptr;
}

Core::ParameterPtr ScriptObject::getParameter(const std::string& name) {
    return parameters[name];
}


void ScriptObject::deleteParameter(const std::string& name) {
    parameters[name] = nullptr;
}

} // namespace Scripting