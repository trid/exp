#ifndef ACTION_WOODCUTTING_H
#define ACTION_WOODCUTTING_H

#include "action.h"
#include "../ai/actors/agent.h"

namespace Core::Actions {

class ActionWoodcutting : public Action {
public:
    explicit ActionWoodcutting(AI::Actors::Agent* actor, Core::World& world);

    virtual bool isValid();
    virtual void update(int delta);
    virtual int progress();
    virtual bool isFinished();

private:
    int _time = 0;
    int _interval = 200;

    const Core::World& _world;
};

} // namespace Core::Actions

#endif // ACTION_WOODCUTTING_H