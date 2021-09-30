#include "action.h"
#include "../ai/actor.h"

class ActionHunting: public Action {
private:
    int time = 0;
    int interval;
public:
    explicit ActionHunting(Actor* actor, World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};