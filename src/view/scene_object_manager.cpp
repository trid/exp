#include "scene_object_manager.h"

#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "../location.h"
#include "../location_type.h"
#include "../world_map.h"
#include "../world.h"

#include "constants.h"
#include "map_object_view.h"
#include "view_facade.h"

using boost::property_tree::ptree;
using boost::property_tree::xml_parser::trim_whitespace;

namespace View {

SceneObjectManager::SceneObjectManager(ViewFacade& view, Core::World& world) {
    loadSprites(view);
    createObjects(world);
}

void SceneObjectManager::loadSprites(ViewFacade& view) {
    ptree pt;
    read_xml(kLocationsImagesDataPath, pt, trim_whitespace);

    auto locationTypes = pt.get_child(kLocationKey);

    for (auto& loc: locationTypes) {
        const auto& type = loc.second.get<std::string>(kLocationTypeKey);
        const auto& image = loc.second.get<std::string>(kSpriteNameKey);
        std::stringstream ss;
        ss << kImageResourcesPath << image;
        _sprites[type] = IMG_LoadTexture(view.getWindow().getRenderer(), ss.str().c_str());
    }
}

void SceneObjectManager::createObjects(Core::World& world) {
    auto& locations = world.getWorldMap().getLocations();

    for (auto& item: locations) {
        const auto& location = *item.second;
        _mapObjects.push_back(std::make_unique<MapObjectView>(location, _sprites[location.getType().getName()]));
    }
}

void SceneObjectManager::draw(const Window& window) {
    for (auto& object: _mapObjects) {
        object->draw(window.getRenderer());
    }
}

} // namespace View