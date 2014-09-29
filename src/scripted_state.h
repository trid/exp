#include "state.h"

#include <string>

#include "lua.hpp"

using std::string;

class ScriptedState: public State {
private:
    string tableName;
    void callFunction(Actor *actor, const string &function);
public:
    ScriptedState(const string& tableName);
    virtual void enter(Actor* actor);
    virtual void execute(Actor *actor);
    virtual void exit(Actor *actor);

    virtual void processMessage(Actor *actor, Message &message);
};