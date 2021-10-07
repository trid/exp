#include "scene_object_manager.h"

#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "../location.h"
#include "../location_type.h"

#include "constants.h"
#include "map_object_view.h"
#include "view_facade.h"

using boost::property_tree::ptree;
using boost::property_tree::xml_parser::trim_whitespace;

extern View::SceneObjectManager* g_sceneObjectManager;

namespace View {

MapObjectView* SceneObjectManager::createMapObject(Core::Location* location) {
    MapObjectView* ptr = new MapObjectView();
    ptr->location = location;
    ptr->image = sprites[location->getType()->getName()];
    mapObjects[location->getName()] = MapObjectPtr(ptr);
    return ptr;
}

void SceneObjectManager::removeSceneObject(const string& name) {
    mapObjects[name] = nullptr;
}

MapObjectPtr SceneObjectManager::getMapObject(const string& name) {
    return mapObjects[name];
}

void SceneObjectManager::draw(SDL_Renderer* renderer) {
    for (auto& ptr: mapObjects) {
        ptr.second->draw(renderer);
    }
}

SceneObjectManager::SceneObjectManager(ViewFacade& view) {
    ptree pt;
    read_xml(kLocationsImagesDataPath, pt, trim_whitespace);

    auto locationTypes = pt.get_child(kLocationKey);

    for (auto& loc: locationTypes) {
        const string& type = loc.second.get<string>(kLocationTypeKey);
        const string& image = loc.second.get<string>(kSpriteNameKey);
        std::stringstream ss;
        ss << kImageResourcesPath << image;
        sprites[type] = IMG_LoadTexture(view.getWindow().getRenderer(), ss.str().c_str());
    }

    g_sceneObjectManager = this;
}

} // namespace View