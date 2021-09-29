#ifndef SCENE_OBJECT_MANAGER_H
#define SCENE_OBJECT_MANAGER_H

#include <string>
#include <unordered_map>
#include <list>
#include "map_object_view.h"

using std::unordered_map;
using std::list;
using std::string;

class Location;
class View;

class SceneObjectManager {
public:
    SceneObjectManager(View& view);

    MapObjectView *createMapObject(Location *location);
    void removeSceneObject(const string& name);
    MapObjectPtr getMapObject(const string& name);
    void draw(SDL_Renderer* renderer);
private:
    unordered_map<string, MapObjectPtr> mapObjects;
    unordered_map<string, SDL_Texture*> sprites;
};

#endif