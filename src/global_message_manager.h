#ifndef UI_MESSAGE_MANAGER_H
#define UI_MESSAGE_MANAGER_H

#include <memory>
#include <string>
#include <unordered_map>
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

class MessageListener {
public:
    virtual bool listen(MessageData const& messageData) = 0;
};

using MessageListenerPtr = std::unique_ptr<MessageListener>;

class GlobalMessageManager {
public:
    GlobalMessageManager() = default;
    GlobalMessageManager(const GlobalMessageManager&) = delete;

    void addListener(const std::string& name, MessageListenerPtr listener);
    void removeListener(const std::string& name);
    void sendMessage(const std::string& name, const MessageData& data);
private:
    std::unordered_map<std::string, MessageListenerPtr> _listeners;
};

} // namespace Core

#endif