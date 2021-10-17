#include "script_functions.h"

#include <iostream>

#include "lua.hpp"

#include "../constants.h"
#include "../world.h"

#include "../view/view_facade.h"

#include "constants.h"


View::ViewFacade* g_view = nullptr;
View::Widgets::GUIPanel* g_panel;

namespace Scripting {

void print(const std::string& message) {
    std::cout << kScriptMessagePrefix << message;
}

void setState(Core::AI::Actors::Agent& actor, const std::string& stateName, Core::AI::StateManager& stateManager) {
    if (stateName.empty()) {
        actor.setBehaviourStep(boost::none);
    } else {
        auto behaviour = stateManager.getBehaviour(stateName);
        actor.setBehaviourStep(behaviour->getStartingStep());
    }
}

void setReaction(Core::AI::Actors::Agent& actor, const std::string& reactionType, const std::string& behaviourName) {
    actor.setReactor(reactionType, behaviourName);
}

//Agent registry
Core::AI::Actors::Agent& createActor(Core::AI::Actors::AgentsRegistry& actorsRegistry, Core::World& world) {
    return actorsRegistry.createAgent(world, *g_panel);
}

//Scene objects
void createSceneObject(const std::string& type, const std::string& name, int x, int y, Core::World& world) {
    const auto& locationType = world.getLocationTypeManager().getLocationType(name);
    world.getWorldMap().addLocation(locationType, name, x, y);
}

} // namespace Scripting