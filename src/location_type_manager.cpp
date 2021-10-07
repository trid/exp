#include "location_type_manager.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "constants.h"
#include "location_type.h"

using boost::property_tree::ptree;
using boost::property_tree::xml_parser::trim_whitespace;

namespace Core {

LocationTypeManager::LocationTypeManager() {
    ptree pt;
    read_xml(kLocationTypesPath, pt, trim_whitespace);

    auto locationTypes = pt.get_child(kLocationTypesKey);

    for (auto& loc: locationTypes) {
        auto subtree = loc.second;
        const std::string& name = subtree.get<std::string>(kLocationNameKey);
        LocationType* locationType = new LocationType(name);
        for (auto action: subtree.get_child(kLocationActionsKey)) {
            locationType->actions.emplace(action.second.data());
        }
        types[locationType->getName()] = locationType;
    }
}

} // namespace Core