#ifndef UI_MESSAGE_MANAGER_H
#define UI_MESSAGE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include <boost/optional.hpp>


namespace Core {

class MessageData;

using MessageParameter = std::variant<int, std::string>;

class MessageListener {
public:
    virtual ~MessageListener() = default;

    virtual bool listen(MessageData const& messageData) = 0;
};

using MessageListenerPtr = std::unique_ptr<MessageListener>;

class GlobalMessageBus {
public:
    GlobalMessageBus() = default;
    GlobalMessageBus(const GlobalMessageBus&) = delete;

    void addListener(const std::string& name, MessageListenerPtr listener);
    void sendMessage(const std::string& name, const MessageData& data);
private:
    std::unordered_map<std::string, std::vector<MessageListenerPtr>> _listeners;
};

} // namespace Core

#endif