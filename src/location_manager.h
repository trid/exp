#ifndef LOCATION_MANAGER_H
#define LOCATION_MANAGER_H

#include <list>
#include <string>
#include <unordered_map>
#include "location.h"
#include "view/scene_object_manager.h"

using std::string;
using std::list;
using std::unordered_map;

class LocationTypeManager;

class LocationManager {
public:
    LocationManager(LocationTypeManager& locationTypeManager);

    void
    createLocation(const string& type, const string& name, int xPos, int yPos, SceneObjectManager& sceneObjectManager);
    Location* getLocation(const string& name);
    const list <Location*>& getLocations();
private:
    list<Location*> locations;
    unordered_map<string, Location*> locationsByName;

    LocationTypeManager& _locationTypeManager;
};

#endif // LOCATION_MANAGER_H