#include "action.h"

class ActionDrink: public Action {
private:
    int time = 0;
    int maxTime = 1000;
public:
    ActionDrink(Actor *actor) : Action(actor) {}

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};