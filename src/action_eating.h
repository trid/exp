#include "action.h"
#include "ai/actor.h"
#include "world.h"

class ActionEating: public Action {
public:
    ActionEating(Actor* actor, World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
private:
    int time = 0;
    int maxTime = 1000;

    World& _world;
};
