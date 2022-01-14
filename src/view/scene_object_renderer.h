#ifndef SCENE_OBJECT_MANAGER_H
#define SCENE_OBJECT_MANAGER_H

#include <string>
#include <unordered_map>
#include <vector>

#include "image.h"
#include "map_object_view.h"
#include "window.h"

namespace Core {
class Location;
class World;
} // namespace Core

namespace View {

class MapObjectView;
class ViewFacade;

class SceneObjectRenderer {
public:
    explicit SceneObjectRenderer(ViewFacade& view, Core::World& world);

    void draw(const Window& window);
private:
    void loadSprites(ViewFacade& view);
    void createObjects(Core::World& world);

    std::vector<MapObjectUPtr> _mapObjects;
    std::unordered_map<std::string, Image> _sprites;
};

} // namespace View

#endif