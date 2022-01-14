#include "script_functions.h"

#include <iostream>

#include "../core/constants.h"
#include "../core/world.h"

#include "constants.h"


namespace Scripting {

void print(const std::string& message) {
    std::cout << kScriptMessagePrefix << message;
}

void setState(Core::AI::Agents::Agent& actor, const std::string& stateName, const Core::AI::StateManager& stateManager) {
    if (stateName.empty()) {
        actor.setBehaviourStep(boost::none);
    } else {
        auto behaviour = stateManager.getBehaviour(stateName);
        actor.setBehaviourStep(behaviour->getStartingStep());
    }
}

void setReaction(Core::AI::Agents::Agent& actor, const std::string& reactionType, const std::string& behaviourName) {
    actor.setReactor(reactionType, behaviourName);
}

//Scene objects
void createSceneObject(const std::string& type, const std::string& name, int x, int y, Core::World& world) {
    const auto& locationType = world.getLocationTypeManager().getLocationType(type);
    if (locationType) {
        world.getWorldMap().addLocation(*locationType, name, x, y);
    }
}

} // namespace Scripting