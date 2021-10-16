#include "global_message_manager.h"

#include <iostream>

using std::cout;
using std::endl;

namespace Core {

void MessageData::addParameter(string const& name, Variant const& data) {
    this->data[name] = VariantPtr(new Variant(data));
}

Variant const& MessageData::getParameter(const string& name) {
    VariantPtr param = data[name];
    if (!param) {
        return nonVariant;
    }
    return *param;
}

void GlobalMessageManager::addListener(const string& name, IUIMessageListenerPtr listener) {
    listeners[name] = std::move(listener);
}

void GlobalMessageManager::removeListener(const string& name) {
    listeners.erase(name);
}

void GlobalMessageManager::sendMessage(const string& name, const MessageData& data) {
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