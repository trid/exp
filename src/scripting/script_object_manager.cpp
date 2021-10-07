#include "script_object.h"
#include "script_object_manager.h"

extern Scripting::ScriptObjectManager* g_scriptObjectManager = nullptr;

namespace Scripting {

ScriptObject* ScriptObjectManager::getItem(const std::string& name) {
    return objects[name];
}

void ScriptObjectManager::addItem(const std::string& name, ScriptObject* item) {
    objects[name] = item;
}

void ScriptObjectManager::deleteItem(const std::string& name) {
    delete objects[name];
    objects[name] = nullptr;
}

ScriptObjectManager::ScriptObjectManager() {
    g_scriptObjectManager = this;
}

} // namespace Scripting