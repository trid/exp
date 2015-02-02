#include "ui_message_manager.h"

#include <iostream>

using std::cout;
using std::endl;

void UIMessageData::addParameter(string const& name, Variant const &data){
    this->data[name] = VariantPtr(new Variant(data));
}

Variant const & UIMessageData::getParameter(const string &name) {
    VariantPtr param = data[name];
    if (!param) {
        return nonVariant;
    }
    return *param;
}

void UIMessageManager::addListener(const string &name, IUIMessageListener *listener) {
    listeners[name] = listener;
}

void UIMessageManager::removeListener(const string &name) {
    listeners.erase(name);
}

void UIMessageManager::sendMessage(const string &name, const UIMessageData &data) {
    if (listeners[name]) {
        listeners[name]->listen(data);
    } else {
        for (auto data: listeners) {
            cout << data.first << endl;
        }
        cout << listeners.size() << endl;
    }
}
