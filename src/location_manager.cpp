#include "location_manager.h"
#include "location_type_manager.h"
#include "view/scene_object_manager.h"

namespace Core {

void LocationManager::createLocation(const string& type, const string& name, int xPos, int yPos,
                                     SceneObjectManager& sceneObjectManager) {
    Location* location = new Location(_locationTypeManager.getLocationType(type), name, xPos, yPos);
    locations.push_back(location);
    locationsByName[name] = location;
    sceneObjectManager.createMapObject(location);
}

Location* LocationManager::getLocation(const string& name) {
    return locationsByName[name];
}

const std::vector<Location*>& LocationManager::getLocations() {
    return locations;
}

LocationManager::LocationManager(LocationTypeManager& locationTypeManager) : _locationTypeManager(
        locationTypeManager) {}

}