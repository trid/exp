#include "map_object.h"
#include "scene_object_manager.h"

MapObject *SceneObjectManager::createMapObject(int x, int y, const string &path, const string& name) {
    MapObject* ptr = new MapObject(x, y, path);
    mapObjects[name] = MapObjectPtr(ptr);
    return ptr;
}

void SceneObjectManager::removeSceneObject(const string &name) {
    mapObjects[name] = nullptr;
}

MapObjectPtr SceneObjectManager::getMapObject(const string &name) {
    return mapObjects[name];
}

void SceneObjectManager::draw(SDL_Renderer *renderer) {
    for (auto & ptr: mapObjects) {
        ptr.second->draw(renderer);
    }
}
