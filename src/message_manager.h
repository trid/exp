#ifndef MESSAGE_MANAGER_H
#define MESSAGE_MANAGER_H

#include <string>

using std::string;

static const string MESSAGE_FINISHED_MOVING = "FINISHED_MOVING";

class Message {
public:
    string messageType;
    void* messageData;
};

class MessageManager {
public:
    static MessageManager& getInstance() {
        static MessageManager messageManager;
        return messageManager;
    };

    void dispatchMessage(int actorId, Message& message);
};

#endif