#include "location.h"

namespace Core {

Location::Location(const LocationType& type, const std::string& name, int xPos, int yPos) : _type(type), _name(name),
                                                                                            _xPos(xPos),
                                                                                            _yPos(yPos) {}

const LocationType& Location::getType() const { return _type; }

const std::string& Location::getName() const { return _name; }

void Location::setName(std::string& name) { Location::_name = name; }

int Location::getXPos() const { return _xPos; }

int Location::getYPos() const { return _yPos; }

void Location::setXPos(int xPos) { Location::_xPos = xPos; }

void Location::setYPos(int yPos) { Location::_yPos = yPos; }
}