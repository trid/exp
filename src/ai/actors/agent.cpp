#include "agent.h"

#include <iostream>

#include "../../constants.h"
#include "../../world.h"
#include "../../actions/constants.h"
#include "../../view/view_facade.h"
#include "../../view/widgets/gui_panel.h"

#include "../constants.h"
#include "../behaviour_step.h"


namespace Core::AI::Actors {

Agent::Agent(int id, Core::World& world) :
        id(id),
        _world(world) {}

void Agent::processMessage(Core::Message& message) {

}

void Agent::say(const std::string& message) {
    std::cout << name << ": " << message << std::endl;
    MessageData messageData;
    messageData.addParameter(kAgentPhraseMessageKey, name + ": " + message);
    _world.getGlobalMessageManager().sendMessage(kAgentPhraseMessage, messageData);
}


void Agent::unloadWood() {
    _world.addWood(getItemsCount(Actions::kItemWood));
    removeAllItems(Actions::kItemWood);
}

void Agent::unloadFood() {
    _world.addFood(getItemsCount(Actions::kItemFood));
    removeAllItems(Actions::kItemFood);
}

} // namespace Core::AI::Actors