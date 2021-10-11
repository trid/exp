//
// Created by TriD on 02.10.2021.
//

#ifndef EXP_MAIN_SCRIPT_CONTEXT_H
#define EXP_MAIN_SCRIPT_CONTEXT_H


#include "script_context.h"
#include "script_object_manager.h"

namespace Core {
class World;
}

namespace Core::AI {
class ActorsRegistry;
class StateManager;
}

namespace Scripting {

class MainScriptContext : public Scripting::ScriptContext {
public:
    MainScriptContext(Core::World& world,
                      Core::AI::StateManager& stateManager);

private:
    void registerFunctions();
    void registerClasses();
    void registerGlobals();

    void registerScriptedStates();

    ScriptObjectManager _scriptObjectManager;
    Core::World& _world;
    Core::AI::StateManager& _stateManager;
};

} // namespace Scripting

#endif //EXP_MAIN_SCRIPT_CONTEXT_H
