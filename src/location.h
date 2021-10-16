#ifndef LOCATION_H
#define LOCATION_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

namespace Core {

class LocationType;

class Location {
public:
    Location(const LocationType& type, const std::string& name, int xPos, int yPos);

    [[nodiscard]] const LocationType& getType() const;
    [[nodiscard]] const std::string& getName() const;
    void setName(std::string& name);

    [[nodiscard]] int getXPos() const;
    void setXPos(int xPos);
    [[nodiscard]] int getYPos() const;
    void setYPos(int yPos);

private:
    const LocationType& _type;
    std::string _name;
    int _xPos, _yPos;
};

using LocationUPtr = std::unique_ptr<Location>;
using LocationOpt = boost::optional<Location&>;

} // namespace Core

#endif // LOCATION_H