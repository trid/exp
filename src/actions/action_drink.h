#include "action.h"

namespace Core {
class World;
} // namespace Core

namespace Core::Actions {

class ActionDrink : public Action {
private:
    int time = 0;
    int maxTime;
public:
    ActionDrink(AI::Actors::Agent* actor, Core::World& world);

    bool isValid() override;
    void update(int delta) override;
    int progress() override;
    bool isFinished() override;
};

} // namespace Core::Actions