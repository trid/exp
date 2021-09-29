#ifndef LOCATION_TYPE_MANAGER_H
#define LOCATION_TYPE_MANAGER_H

#include <string>
#include <unordered_map>
#include "location_type.h"

using std::string;
using std::unordered_map;

class LocationTypeManager {
public:
    LocationTypeManager();

    LocationType* getLocationType(string const &name) { return types[name]; }
private:
    unordered_map<string, LocationType*> types;
};

#endif