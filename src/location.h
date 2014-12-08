#include "location_type.h"

class Location {
private:
    LocationType* type;
    string name;
    int xPos, yPos;
public:
    Location(LocationType* type, const string& name, int xPos, int yPos): type(type), name(name), xPos(xPos), yPos(yPos){}

    LocationType *getType() const { return type; }
    void setType(LocationType *type) { Location::type = type; }
    string &getName() const { return name; }
    void setName(string &name) { Location::name = name; }
    int getXPos() const { return xPos; }
    void setXPos(int xPos) { Location::xPos = xPos; }
    int getYPos() const { return yPos; }
    void setYPos(int yPos) { Location::yPos = yPos; }
};