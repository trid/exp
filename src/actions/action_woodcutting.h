#include "action.h"
#include "../ai/actors/agent.h"

namespace Core::Actions {

class ActionWoodcutting : public Action {
private:
    int time = 0;
    int interval = 200;
public:
    explicit ActionWoodcutting(AI::Actors::Agent* actor, Core::World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();
};

} // namespace Core::Actions