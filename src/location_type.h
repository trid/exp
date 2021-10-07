#ifndef LOCATION_TYPE_H
#define LOCATION_TYPE_H

#include <string>
#include <unordered_set>

namespace Core {

class LocationType {
    friend class LocationTypeManager;

private:
    std::string name;
    std::unordered_set <std::string> actions;
public:
    explicit LocationType(const std::string& name);

    const std::string& getName();

    const std::unordered_set <std::string>& getActions();
};

} // namespace Core

#endif // LOCATION_TYPE_H