#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include <string>

using std::string;

class ActorsRegistry;

class Message {
public:
    string messageType;
    void* messageData;
};

class MessageManager {
public:
    explicit MessageManager(ActorsRegistry& actorRegistry);

    void dispatchMessage(int actorId, Message& message);

private:
    ActorsRegistry& _actorRegistry;
};

#endif