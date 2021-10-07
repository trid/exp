#include "state.h"

#include <string>

namespace Scripting {
class ScriptContext;
}

namespace Core::AI {

class ScriptedState : public State {
public:
    ScriptedState(StateManager& stateManager, Scripting::ScriptContext& scriptManager, const std::string& tableName);
    virtual void enter(Actor* actor);
    virtual void execute(Actor* actor);
    virtual void exit(Actor* actor);

    virtual void processMessage(Actor* actor, Core::Message& message);
private:
    Scripting::ScriptContext& _scriptContext;
    const std::string _tableName;
    void callFunction(Actor* actor, const std::string& function);
};

} // namespace Core::AI