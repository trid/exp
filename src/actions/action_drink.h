#ifndef ACTION_DRINK_H
#define ACTION_DRINK_H

#include "action.h"

namespace Core {
class World;
} // namespace Core

namespace Core::Actions {

class ActionDrink : public Action {
public:
    ActionDrink(AI::Actors::Agent& actor, Core::World& world);

    [[nodiscard]] bool isValid() const override;
    void update(int delta) override;
    int progress() override;
    [[nodiscard]] bool isFinished() const override;

private:
    int _time = 0;
    int _maxTime;

    const Core::World& _world;
};

} // namespace Core::Actions

#endif // ACTION_DRINK_H