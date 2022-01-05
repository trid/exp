#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <string>
#include <unordered_map>

#include "behaviour.h"

namespace Scripting {
class ScriptContext;
} // namespace Scripting

namespace Core {
class World;
} // namespace Core

namespace Core::AI {

class StateManager {
public:
    BehaviourOpt getBehaviour(const std::string& name);

    void registerBehaviour(const std::string& behaviourName, const sol::table& startingStep);
private:
    std::unordered_map<std::string, Behaviour> _behaviours;
};

} // namespace Core::AI

#endif