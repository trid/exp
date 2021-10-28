#include "global_message_manager.h"

#include <iostream>

using std::cout;
using std::endl;

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

void GlobalMessageManager::addListener(const std::string& name, IUIMessageListenerPtr listener) {
    listeners[name] = std::move(listener);
}

void GlobalMessageManager::removeListener(const std::string& name) {
    listeners.erase(name);
}

void GlobalMessageManager::sendMessage(const std::string& name, const MessageData& data) {
    if (listeners[name]) {
        listeners[name]->listen(data);
    } else {
        for (auto& listener: listeners) {
            cout << listener.first << endl;
        }
        cout << listeners.size() << endl;
    }
}

} // namespace Core