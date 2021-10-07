#ifndef LOCATION_H
#define LOCATION_H

#include <string>

namespace Core {

class LocationType;

class Location {
public:
    Location(LocationType* type, const std::string& name, int xPos, int yPos);

    [[nodiscard]] LocationType* getType() const;
    void setType(LocationType* type);
    [[nodiscard]] const std::string& getName() const;
    void setName(std::string& name);

    [[nodiscard]] int getXPos() const;
    void setXPos(int xPos);
    [[nodiscard]] int getYPos() const;
    void setYPos(int yPos);

private:
    LocationType* type;
    std::string name;
    int xPos, yPos;
};

} // namespace Core

#endif // LOCATION_H