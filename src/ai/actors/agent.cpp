#include "agent.h"

#include <iostream>

#include "../../constants.h"
#include "../../world.h"
#include "../../actions/constants.h"
#include "../../view/view_facade.h"
#include "../../view/widgets/gui_panel.h"

#include "../constants.h"
#include "../behaviour_step.h"

extern View::Widgets::GUIPanel* g_panel;

namespace Core::AI::Actors {

Agent::Agent(int id, Core::World& world, View::Widgets::GUIPanel& guiPanel) :
        id(id),
        _world(world),
        _guiPanel(guiPanel) {}

void Agent::processMessage(Core::Message& message) {

}

void Agent::say(const string& message) {
    std::cout << name << ": " << message << std::endl;
    g_panel->addMessage(name + ": " + message);
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