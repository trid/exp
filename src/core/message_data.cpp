//
// Created by TriD on 12.01.2022.
//

#include "message_data.h"

namespace Core {

void MessageData::addParameter(std::string const& name, MessageParameter&& parameter) {
    _data[name] = std::move(parameter);
}

boost::optional<const MessageParameter&> MessageData::getParameter(const std::string& name) const {
    auto it = _data.find(name);
    if (it != _data.end()) {
        return it->second;
    }
    return boost::none;
}

}