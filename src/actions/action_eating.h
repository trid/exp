#ifndef ACTION_EATING_H
#define ACTION_EATING_H

#include "action.h"
#include "../ai/actors/agent.h"

namespace Core {
class World;
} // namespace Core

namespace Core::Actions {

class ActionEating : public Action {
public:
    ActionEating(AI::Actors::Agent& actor, Core::World& world);

    [[nodiscard]] bool isValid() const override;
    void update(int delta) override;
    int progress() override;
    [[nodiscard]] bool isFinished() const override;
private:
    int _time = 0;
    int _maxTime;

    Core::World& _world;
};

} // namespace Core::Actions

#endif // ACTION_EATING_H