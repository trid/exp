#include "agent.h"

#include <iostream>

#include "../../core/constants.h"
#include "../../core/message_data.h"
#include "../../core/world.h"

namespace Core::AI::Agents {

Agent::Agent(int id, Core::GlobalMessageManager& globalMessageBus) :
        AgentPositioningData(),
        _id(id),
        _globalMessageBus(globalMessageBus) {}

void Agent::say(const std::string& message) {
    std::cout << _name << ": " << message << std::endl;
    MessageData messageData;
    messageData.addParameter(kAgentPhraseMessageKey, _name + ": " + message);
    _globalMessageBus.sendMessage(kAgentPhraseMessage, messageData);
}

void Agent::setType(const std::string& type) {
    _type = type;
}

int Agent::getID() const { return _id; }

const std::string& Agent::getName() const { return _name; }

void Agent::setName(const std::string& name) { _name = name; }

const std::string& Agent::getType() const {
    return _type;
}

} // namespace Core::AI::Agents