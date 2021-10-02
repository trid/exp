#include "state.h"

#include <string>

using std::string;

class ScriptContext;

class ScriptedState: public State {
public:
    ScriptedState(StateManager& stateManager, ScriptContext& scriptManager, const string& tableName);
    virtual void enter(Actor* actor);
    virtual void execute(Actor *actor);
    virtual void exit(Actor *actor);

    virtual void processMessage(Actor *actor, Message &message);
private:
    ScriptContext& _scriptContext;
    const string _tableName;
    void callFunction(Actor *actor, const string &function);
};