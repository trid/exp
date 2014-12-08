#include "location_manager.h"
#include "location_type_manager.h"

void LocationManager::createLocation(const string &type, const string &name, int xPos, int yPos) {
    Location* location = new Location(LocationTypeManager::getInstance().getLocationType(type), name, xPos, yPos);
    locations.push_back(location);
    locationsByName[name] = location;
}

Location *LocationManager::getLocation(const string &name) {
    return locationsByName[name];
}

const list<Location *> &LocationManager::getLocations() {
    return locations;
}
