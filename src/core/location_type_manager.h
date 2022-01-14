#ifndef LOCATION_TYPE_MANAGER_H
#define LOCATION_TYPE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>

#include <boost/optional.hpp>

#include "location_type.h"

namespace Core {

using LocationTypeOpt = boost::optional<const LocationType&>;

class LocationTypeManager {
public:
    LocationTypeManager();

    LocationTypeOpt getLocationType(std::string const& name) const;

private:
    std::unordered_map<std::string, LocationType> _types;
};

} // namespace Core

#endif