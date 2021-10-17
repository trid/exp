#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include <string>

namespace Core {

namespace AI::Actors {
class AgentsRegistry;
} // namespace AI::Actors

class Message {
public:
    std::string messageType;
    void* messageData;
};

class MessageManager {
public:
    explicit MessageManager(AI::Actors::AgentsRegistry& actorRegistry);

    void dispatchMessage(int actorId, Message& message);

private:
    AI::Actors::AgentsRegistry& _actorRegistry;
};

} // namespace Core

#endif