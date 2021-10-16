//
// Created by TriD on 16.10.2021.
//

#include "world_map.h"

#include "location_type.h"

namespace Core {

void WorldMap::addLocation(const LocationType& type, const std::string& name, int xPos, int yPos) {
    _mapObjects.emplace(name, std::make_unique<Location>(type, name, xPos, yPos));
}

void WorldMap::removeLocation(const std::string& name) {
    _mapObjects.erase(name);
}

LocationOpt WorldMap::getLocation(const std::string& name) {
    auto it = _mapObjects.find(name);
    if (it != _mapObjects.end()) {
        return *it->second;
    }
    return boost::none;
}

LocationOpt WorldMap::getLocation(const std::string& name) const {
    auto it = _mapObjects.find(name);
    if (it != _mapObjects.end()) {
        return *it->second;
    }
    return boost::none;
}

const std::unordered_map<std::string, LocationUPtr>& WorldMap::getLocations() const {
    return _mapObjects;
}


}