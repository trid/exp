#ifndef SCENE_OBJECT_MANAGER_H
#define SCENE_OBJECT_MANAGER_H

#include <string>
#include <unordered_map>
#include <list>
#include "map_object_view.h"

class Location;
class View;

namespace Core {
class Location;
} // namespace Core

class SceneObjectManager {
public:
    SceneObjectManager(View& view);

    MapObjectView *createMapObject(Core::Location *location);
    void removeSceneObject(const string& name);
    MapObjectPtr getMapObject(const string& name);
    void draw(SDL_Renderer* renderer);
private:
    std::unordered_map<string, MapObjectPtr> mapObjects;
    std::unordered_map<string, SDL_Texture*> sprites;
};

#endif