#ifndef ACTION_HUNTING_H
#define ACTION_HUNTING_H

#include "action.h"

namespace Core::AI::Actors {
class Agent;
}

namespace Core::Actions {

class ActionHunting : public Action {
public:
    explicit ActionHunting(AI::Actors::Agent* actor, Core::World& world);

    bool isValid() override;
    void update(int delta) override;
    int progress() override;
    bool isFinished() override;

private:
    int _time = 0;
    int _interval;

    const Core::World& _world;
};

} // namespace Core::Actions

#endif // ACTION_HUNTING_H