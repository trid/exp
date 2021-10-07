#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include <string>

class ActorsRegistry;

namespace Core {

class Message {
public:
    std::string messageType;
    void* messageData;
};

class MessageManager {
public:
    explicit MessageManager(ActorsRegistry& actorRegistry);

    void dispatchMessage(int actorId, Message& message);

private:
    ActorsRegistry& _actorRegistry;
};

} // namespace Core

#endif