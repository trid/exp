#include <iostream>
#include "actor.h"

using namespace std;

class StateFinished: public State {
public:
    virtual void enter(Actor* actor){ actor->say("Yup! I've finished!"); }
    virtual void execute(Actor* actor) { actor->say("Enjoing myself."); }
    virtual void exit(Actor* actor){ actor->say("Returning to work"); }

    virtual void processMessage(Actor *actor, Message &message);

    static StateFinished* getInstance() {
        static StateFinished stateFinished;
        return &stateFinished;
    }
};