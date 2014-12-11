#include <string>
#include <unordered_map>
#include "location_type.h"

using std::string;
using std::unordered_map;

class LocationTypeManager {
private:
    LocationTypeManager();
    unordered_map<string, LocationType*> types;
public:
    static LocationTypeManager & getInstance(){
        static LocationTypeManager manager;
        return manager;
    }
    LocationType* getLocationType(string const &name) { return types[name]; }
};