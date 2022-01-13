#ifndef SCRIPT_FUNCTIONS_H
#define SCRIPT_FUNCTIONS_H

#include "../ai/state_manager.h"

namespace Core::AI::Actors {
class AgentsRegistry;
class Agent;
}

namespace Scripting {

// Utils
void print(const std::string& message);

// Actors
void setState(Core::AI::Actors::Agent& actor, const std::string& stateName, const Core::AI::StateManager& stateManager);
void setReaction(Core::AI::Actors::Agent& actor, const std::string& reactionType, const std::string& behaviourName);
int getId(lua_State* state);

// Actors registry
Core::AI::Actors::Agent& createActor(Core::AI::Actors::AgentsRegistry& actorsRegistry, Core::World& world);

// Locations
void createSceneObject(const std::string& type, const std::string& name, int x, int y, Core::World& world);

} // namespace Scripting

#endif // SCRIPT_FUNCTIONS_H