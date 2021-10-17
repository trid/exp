#include "action.h"

namespace Core::AI::Actors {
class Agent;
}

namespace Core::Actions {

class ActionHunting : public Action {
private:
    int time = 0;
    int interval;
public:
    explicit ActionHunting(AI::Actors::Agent* actor, Core::World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};

} // namespace Core::Actions