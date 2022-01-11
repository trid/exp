//
// Created by TriD on 12.01.2022.
//

#ifndef EXP_MESSAGE_DATA_H
#define EXP_MESSAGE_DATA_H

#include <string>
#include <variant>

#include <boost/optional.hpp>

namespace Core {

using MessageParameter = std::variant<int, std::string>;

class MessageData {
public:
    void addParameter(const std::string& name, MessageParameter&& parameter);
    boost::optional<const MessageParameter&> getParameter(const std::string& name) const;

private:
    std::unordered_map<std::string, MessageParameter> _data;
};

}

#endif //EXP_MESSAGE_DATA_H
