#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include <string>

namespace Core {

namespace AI {
class ActorsRegistry;
}

class Message {
public:
    std::string messageType;
    void* messageData;
};

class MessageManager {
public:
    explicit MessageManager(AI::ActorsRegistry& actorRegistry);

    void dispatchMessage(int actorId, Message& message);

private:
    AI::ActorsRegistry& _actorRegistry;
};

} // namespace Core

#endif