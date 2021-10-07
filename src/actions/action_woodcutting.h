#include "action.h"
#include "../ai/actor.h"

namespace Core::Actions {

class ActionWoodcutting : public Action {
private:
    int time = 0;
    int interval = 200;
public:
    explicit ActionWoodcutting(AI::Actor* actor, Core::World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};

} // namespace Core::Actions