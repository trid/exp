#ifndef ACTION_WOODCUTTING_H
#define ACTION_WOODCUTTING_H

#include "action.h"

namespace Core::Actions {

class ActionWoodcutting : public Action {
public:
    explicit ActionWoodcutting(AI::Actors::Agent* actor, Core::World& world);

    [[nodiscard]] bool isValid() const override;
    void update(int delta) override;
    int progress() override;
    [[nodiscard]] bool isFinished() const override;

private:
    int _time = 0;
    int _interval = 200;

    const Core::World& _world;
};

} // namespace Core::Actions

#endif // ACTION_WOODCUTTING_H