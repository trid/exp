#include "action.h"

class ActionDrink: public Action {
private:
    int time = 0;
    int maxTime;
public:
    ActionDrink(Actor* actor, World& world);

    bool isValid() override;
    void update(int delta) override;
    int progress() override;
    bool isFinished() override;
};