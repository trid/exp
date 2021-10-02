#include "script_object.h"
#include "script_object_manager.h"

ScriptObject *ScriptObjectManager::getItem(const string &name) {
    return objects[name];
}

void ScriptObjectManager::addItem(const string &name, ScriptObject *item) {
    objects[name] = item;
}

void ScriptObjectManager::deleteItem(const string &name) {
    delete objects[name];
    objects[name] = nullptr;
}
