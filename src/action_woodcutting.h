#include "action.h"
#include "ai/actor.h"

class ActionWoodcutting: public Action {
private:
    int time = 0;
    int interval = 200;
public:
    ActionWoodcutting(Actor *actor) : Action(actor) {}

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};