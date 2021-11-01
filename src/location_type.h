#ifndef LOCATION_TYPE_H
#define LOCATION_TYPE_H

#include <string>
#include <unordered_set>

namespace Core {

class LocationType {
public:
    explicit LocationType(std::string&& name, std::unordered_set<std::string>&& actions, int width, int height);

    const std::string& getName() const;
    const std::unordered_set <std::string>& getActions() const;

    int getWidth() const;
    int getHeight() const;
private:
    std::string _name;
    std::unordered_set <std::string> _actions;

    int _width;
    int _height;
};

} // namespace Core

#endif // LOCATION_TYPE_H