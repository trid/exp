#include "action.h"
#include "../ai/actor.h"
#include "../world.h"

class ActionEating: public Action {
public:
    ActionEating(Actor* actor, World& world);

    bool isValid() override;
    void update(int delta) override;
    int progress() override;
    bool isFinished() override;
private:
    int time = 0;
    int maxTime;

    World& _world;
};
