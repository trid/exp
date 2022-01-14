#include "location_type.h"

namespace Core {

LocationType::LocationType(std::string&& name, std::unordered_set<std::string>&& actions, int width, int height)
        : _name(name), _actions(actions), _width(width), _height(height) {}

const std::string& LocationType::getName() const { return _name; }

const std::unordered_set<std::string>& LocationType::getActions() const { return _actions; }

int LocationType::getWidth() const {
    return _width;
}

int LocationType::getHeight() const {
    return _height;
}

}