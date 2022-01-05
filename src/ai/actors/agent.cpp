#include "agent.h"

#include <iostream>

#include "../../constants.h"
#include "../../world.h"
#include "../../actions/constants.h"
#include "../../view/view_facade.h"

#include "../constants.h"
#include "../behaviour_step.h"


namespace Core::AI::Actors {

Agent::Agent(int id, Core::GlobalMessageManager& globalMessageBus) :
        AgentPositioningData(),
        id(id),
        _globalMessageBus(globalMessageBus) {}

void Agent::processMessage(Core::Message& message) {

}

void Agent::say(const std::string& message) {
    std::cout << name << ": " << message << std::endl;
    MessageData messageData;
    messageData.addParameter(kAgentPhraseMessageKey, name + ": " + message);
    _globalMessageBus.sendMessage(kAgentPhraseMessage, messageData);
}

} // namespace Core::AI::Actors