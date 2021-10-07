#ifndef SCENE_OBJECT_MANAGER_H
#define SCENE_OBJECT_MANAGER_H

#include <string>
#include <unordered_map>
#include <list>

#include "map_object_view.h"

class Location;

namespace Core {
class Location;
} // namespace Core

namespace View {

class MapObjectView;
class ViewFacade;

class SceneObjectManager {
public:
    SceneObjectManager(ViewFacade& view);

    MapObjectView* createMapObject(Core::Location* location);
    void removeSceneObject(const std::string& name);
    MapObjectPtr getMapObject(const std::string& name);
    void draw(SDL_Renderer* renderer);
private:
    std::unordered_map<std::string, MapObjectPtr> mapObjects;
    std::unordered_map<std::string, SDL_Texture*> sprites;
};

} // namespace View

#endif