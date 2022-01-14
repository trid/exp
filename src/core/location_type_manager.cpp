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
        auto name = subtree.get<std::string>(kLocationNameKey);

        std::unordered_set<std::string> actions;
        for (auto action: subtree.get_child(kLocationActionsKey)) {
            actions.emplace(action.second.data());
        }

        int width = subtree.get<int>(kLocationWidthKey);
        int height = subtree.get<int>(kLocationHeightKey);

        _types.emplace(std::piecewise_construct, std::make_tuple(name),
                       std::make_tuple(name, std::move(actions), width, height));
    }
}

LocationTypeOpt LocationTypeManager::getLocationType(const std::string& name) const {
    auto iter = _types.find(name);
    if (iter != _types.end()) {
        return iter->second;
    }
    return boost::none;
}

} // namespace Core