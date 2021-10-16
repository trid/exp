#ifndef UI_MESSAGE_MANAGER_H
#define UI_MESSAGE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>

using std::shared_ptr;
using std::string;
using std::unordered_map;

namespace Core {

union VariantUnion {
    int asInt;
    double asFloat;
    char asChar;
    void* asPointer;
};

class Variant {
public:
    VariantUnion data;
    bool exists = false;

    Variant(const VariantUnion& data) : data(data), exists(true) {}

    Variant() : data(VariantUnion()), exists(false) {}
};

typedef shared_ptr<Variant> VariantPtr;

class MessageData {
private:
    unordered_map<string, VariantPtr> data;
    Variant nonVariant;
public:
    MessageData() {}

    void addParameter(const string& name, const Variant& data);
    Variant const& getParameter(const string& name);
};

class MessageListener {
public:
    virtual bool listen(MessageData const& messageData) = 0;
};

using IUIMessageListenerPtr = std::unique_ptr<MessageListener>;

class GlobalMessageManager {
public:
    GlobalMessageManager() = default;
    GlobalMessageManager(const GlobalMessageManager&) = delete;

    void addListener(const string& name, IUIMessageListenerPtr listener);
    void removeListener(const string& name);
    void sendMessage(const string& name, const MessageData& data);
private:
    unordered_map<string, IUIMessageListenerPtr> listeners;
};

} // namespace Core

#endif