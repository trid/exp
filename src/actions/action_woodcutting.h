#ifndef ACTION_WOODCUTTING_H
#define ACTION_WOODCUTTING_H

#include "action.h"

namespace Core::Actions {

class ActionWoodcutting : public Action {
public:
    explicit ActionWoodcutting(AI::Actors::Agent* actor, Core::World& world);

    bool isValid() override;
    void update(int delta) override;
    int progress() override;
    bool isFinished() override;

private:
    int _time = 0;
    int _interval = 200;

    const Core::World& _world;
};

} // namespace Core::Actions

#endif // ACTION_WOODCUTTING_H