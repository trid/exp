#include "location_type_manager.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::xml_parser::trim_whitespace;

LocationTypeManager::LocationTypeManager() {
    ptree pt;
    read_xml("res/locations/location_types.xml", pt, trim_whitespace);

    auto locationTypes = pt.get_child("types");

    for (auto& loc: locationTypes) {
        auto subtree = loc.second;
        const string& name = subtree.get<string>("name");
        LocationType* locationType = new LocationType(name);
        for (auto action: subtree.get_child("actions")) {
            locationType->actions.emplace(action.second.data());
        }
        types[locationType->getName()] = locationType;
    }
}
