#include "action.h"
#include "ai/actor.h"

class ActionHunting: public Action {
private:
    int time = 0;
    int interval = 300;
public:
    ActionHunting(Actor *actor) : Action(actor) { }

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};