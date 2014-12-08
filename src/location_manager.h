#include <list>
#include <string>
#include <unordered_map>
#include "location.h"

using std::string;
using std::list;
using std::unordered_map;

class LocationManager {
private:
    LocationManager(){};
    list<Location*> locations;
    unordered_map<string, Location*> locationsByName;
public:
    static LocationManager& getInstance(){
        static LocationManager locationManager;
        return locationManager;
    }

    void createLocation(const string &type, const string &name, int xPos, int yPos);
    Location* getLocation(const string& name);
    const list <Location*>& getLocations();
};