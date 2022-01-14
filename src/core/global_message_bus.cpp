#include "global_message_bus.h"

namespace Core {

void GlobalMessageBus::addListener(const std::string& name, MessageListenerPtr listener) {
    _listeners[name].push_back(std::move(listener));
}

void GlobalMessageBus::sendMessage(const std::string& name, const MessageData& data) {
    auto iter = _listeners.find(name);
    if (iter != _listeners.end()) {
        for (auto& item: iter->second) {
            item->listen(data);
        }
    }
}

} // namespace Core