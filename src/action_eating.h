#include "action.h"
#include "ai/actor.h"

class ActionEating: public Action {
private:
    int time = 0;
    int maxTime = 1000;
public:
    ActionEating(Actor *actor) : Action(actor) { }

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};
