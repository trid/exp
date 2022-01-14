#ifndef SCRIPT_FUNCTIONS_H
#define SCRIPT_FUNCTIONS_H

#include "../ai/state_manager.h"

namespace Core::AI::Agents {
class AgentsRegistry;
class Agent;
}

namespace Scripting {

// Utils
void print(const std::string& message);

// Agents
void setState(Core::AI::Agents::Agent& actor, const std::string& stateName, const Core::AI::StateManager& stateManager);
void setReaction(Core::AI::Agents::Agent& actor, const std::string& reactionType, const std::string& behaviourName);
int getId(lua_State* state);

// Locations
void createSceneObject(const std::string& type, const std::string& name, int x, int y, Core::World& world);

} // namespace Scripting

#endif // SCRIPT_FUNCTIONS_H