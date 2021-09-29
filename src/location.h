#ifndef LOCATION_H
#define LOCATION_H

#include <string>

#include "location_type.h"

class LocationType;

class Location {
public:
    Location(LocationType* type, const std::string& name, int xPos, int yPos): type(type), name(name), xPos(xPos), yPos(yPos){}

    LocationType* getType() const { return type; }
    void setType(LocationType* type) { Location::type = type; }
    const std::string& getName() const { return name; }
    void setName(std::string& name) { Location::name = name; }
    int getXPos() const { return xPos; }
    void setXPos(int xPos) { Location::xPos = xPos; }
    int getYPos() const { return yPos; }
    void setYPos(int yPos) { Location::yPos = yPos; }
private:
    LocationType* type;
    std::string name;
    int xPos, yPos;
};

#endif // LOCATION_H