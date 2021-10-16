//
// Created by TriD on 16.10.2021.
//

#ifndef EXP_WORLD_MAP_H
#define EXP_WORLD_MAP_H

#include <string>
#include <unordered_map>

#include "location.h"

namespace Core {

class WorldMap {
public:
    void addLocation(const LocationType& type, const std::string& name, int xPos, int yPos);
    void removeLocation(const std::string& name);
    LocationOpt getLocation(const std::string& name);
    LocationOpt getLocation(const std::string& name) const;
    const std::unordered_map<std::string, LocationUPtr>& getLocations() const;
private:
    std::unordered_map<std::string, LocationUPtr> _mapObjects;
};

} // namespace Core

#endif //EXP_WORLD_MAP_H
