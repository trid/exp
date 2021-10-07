#include "location_type.h"

namespace Core {

LocationType::LocationType(const std::string& name) : name(name) {}

const std::string& LocationType::getName() { return name; }

const std::unordered_set<std::string>& LocationType::getActions() { return actions; }

}