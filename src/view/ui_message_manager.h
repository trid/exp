#ifndef UI_MESSAGE_MANAGER_H
#define UI_MESSAGE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>

using std::shared_ptr;
using std::string;
using std::unordered_map;

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

    Variant(const VariantUnion& data): data(data), exists(true) {}
    Variant(): data(VariantUnion()), exists(false) {}
};

typedef shared_ptr<Variant> VariantPtr;

class UIMessageData {
private:
    unordered_map<string, VariantPtr> data;
    Variant nonVariant;
public:
    UIMessageData() {}
    void addParameter(const string& name, const Variant& data);
    Variant const & getParameter(const string &name);
};

class IUIMessageListener{
public:
    virtual bool listen(UIMessageData const &messageData) = 0;
};

using IUIMessageListenerPtr = std::unique_ptr<IUIMessageListener>;

class UIMessageManager {
public:
    UIMessageManager() = default;
    UIMessageManager(const UIMessageManager&) = delete;

    void addListener(const string& name, IUIMessageListenerPtr listener);
    void removeListener(const string& name);
    void sendMessage(const string& name, const UIMessageData& data);
private:
    unordered_map<string, IUIMessageListenerPtr> listeners;
};

#endif