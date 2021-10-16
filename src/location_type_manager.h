#ifndef LOCATION_TYPE_MANAGER_H
#define LOCATION_TYPE_MANAGER_H

#include <string>
#include <unordered_map>

namespace Core {

class LocationType;

class LocationTypeManager {
public:
    LocationTypeManager();

    const LocationType& getLocationType(std::string const& name) const;

private:
    std::unordered_map<std::string, LocationType*> types;
};

} // namespace Core

#endif