#include "action.h"
#include "../ai/actor.h"

namespace Core::Actions {

class ActionHunting : public Action {
private:
    int time = 0;
    int interval;
public:
    explicit ActionHunting(Actor* actor, Core::World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};

} // namespace Core::Actions