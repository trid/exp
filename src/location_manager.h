#ifndef LOCATION_MANAGER_H
#define LOCATION_MANAGER_H

#include <string>
#include <unordered_map>
#include <vector>
#include "location.h"
#include "view/scene_object_manager.h"

namespace Core {

class LocationTypeManager;

class LocationManager {
public:
    LocationManager(LocationTypeManager& locationTypeManager);

    void createLocation(const string& type,
                        const string& name,
                        int xPos, int yPos,
                        SceneObjectManager& sceneObjectManager);
    Location* getLocation(const string& name);
    const std::vector<Location*>& getLocations();

private:
    std::vector<Location*> locations;
    std::unordered_map<string, Location*> locationsByName;

    LocationTypeManager& _locationTypeManager;
};

} // namespace Core

#endif // LOCATION_MANAGER_H