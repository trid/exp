#ifndef ACTION_HUNTING_H
#define ACTION_HUNTING_H

#include "action.h"

namespace Core::AI::Agents {
class Agent;
}

namespace Core::Actions {

class ActionHunting : public Action {
public:
    explicit ActionHunting(AI::Agents::Agent& actor, Core::World& world);

    [[nodiscard]] bool isValid() const override;
    void update(int delta) override;
    int progress() override;
    [[nodiscard]] bool isFinished() const override;

private:
    int _time = 0;
    int _interval;

    const Core::World& _world;
};

} // namespace Core::Actions

#endif // ACTION_HUNTING_H