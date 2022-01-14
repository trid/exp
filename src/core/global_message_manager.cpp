#include "global_message_manager.h"

namespace Core {

void GlobalMessageManager::addListener(const std::string& name, MessageListenerPtr listener) {
    _listeners[name].push_back(std::move(listener));
}

void GlobalMessageManager::sendMessage(const std::string& name, const MessageData& data) {
    auto iter = _listeners.find(name);
    if (iter != _listeners.end()) {
        for (auto& item: iter->second) {
            item->listen(data);
        }
    }
}

} // namespace Core