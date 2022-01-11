#include "global_message_manager.h"

namespace Core {

void GlobalMessageManager::addListener(const std::string& name, MessageListenerPtr listener) {
    _listeners[name] = std::move(listener);
}

void GlobalMessageManager::removeListener(const std::string& name) {
    _listeners.erase(name);
}

void GlobalMessageManager::sendMessage(const std::string& name, const MessageData& data) {
    if (_listeners[name]) {
        _listeners[name]->listen(data);
    }
}

} // namespace Core