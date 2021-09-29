#include "map_object_view.h"
#include "scene_object_manager.h"
#include "view.h"
#include "../location.h"

#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using std::stringstream;

using boost::property_tree::ptree;
using boost::property_tree::xml_parser::trim_whitespace;

extern SceneObjectManager* g_sceneObjectManager;

MapObjectView *SceneObjectManager::createMapObject(Location *location) {
    MapObjectView * ptr = new MapObjectView();
    ptr->location = location;
    ptr->image = sprites[location->getType()->getName()];
    mapObjects[location->getName()] = MapObjectPtr(ptr);
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

SceneObjectManager::SceneObjectManager(View& view) {
    ptree pt;
    read_xml("res/locations/location_images.xml", pt, trim_whitespace);

    auto locationTypes = pt.get_child("locations");

    for (auto& loc: locationTypes) {
        const string& type = loc.second.get<string>("name");
        const string& image = loc.second.get<string>("sprite");
        stringstream ss;
        ss << "res/img/" << image;
        sprites[type] = IMG_LoadTexture(view.getRenderer(), ss.str().c_str());
    }

    g_sceneObjectManager = this;
}
