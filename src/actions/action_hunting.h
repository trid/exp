#include "action.h"

namespace Core::AI::Actors {
class Actor;
}

namespace Core::Actions {

class ActionHunting : public Action {
private:
    int time = 0;
    int interval;
public:
    explicit ActionHunting(AI::Actors::Actor* actor, Core::World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};

} // namespace Core::Actions