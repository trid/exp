#ifndef LOCATION_TYPE_MANAGER_H
#define LOCATION_TYPE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>

namespace Core {

class LocationType;

class LocationTypeManager {
public:
    LocationTypeManager();

    const LocationType& getLocationType(std::string const& name) const;

private:
    std::unordered_map<std::string, std::unique_ptr<LocationType>> _types;
};

} // namespace Core

#endif