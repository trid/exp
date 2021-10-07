#include "location.h"

namespace Core {

Location::Location(LocationType* type, const std::string& name, int xPos, int yPos) : type(type), name(name), xPos(xPos),
                                                                                      yPos(yPos) {}

LocationType* Location::getType() const { return type; }

void Location::setType(LocationType* type) { Location::type = type; }

const std::string& Location::getName() const { return name; }

void Location::setName(std::string& name) { Location::name = name; }

int Location::getXPos() const { return xPos; }

int Location::getYPos() const { return yPos; }

void Location::setXPos(int xPos) { Location::xPos = xPos; }

void Location::setYPos(int yPos) { Location::yPos = yPos; }
}