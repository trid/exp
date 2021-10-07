#include "action.h"
#include "../ai/actor.h"

namespace Core {
class World;
} // namespace Core

class ActionEating: public Action {
public:
    ActionEating(Actor* actor, Core::World& world);

    bool isValid() override;
    void update(int delta) override;
    int progress() override;
    bool isFinished() override;
private:
    int time = 0;
    int maxTime;

    Core::World& _world;
};
