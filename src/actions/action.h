#ifndef ACTION_H
#define ACTION_H

#include <memory>

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Actors {
class Agent;
} // namespace Core::AI

namespace Core::Actions {

class Action {
private:
    bool running = true;
protected:
    AI::Actors::Agent* actor;
public:
    virtual bool isValid() = 0;
    virtual void update(int delta) = 0;
    virtual int progress() = 0;
    virtual bool isFinished() = 0;

    [[nodiscard]] bool isRunning() const;

    void stop();

    AI::Actors::Agent* getActor();

    Action(AI::Actors::Agent* actor, Core::World&);
};

class VirtualActionFactory {
public:
    virtual Action* createAction(AI::Actors::Agent* actor, Core::World& world) = 0;
};

template<class T>
class ActionFactory : public VirtualActionFactory {
    Action* createAction(AI::Actors::Agent* actor, Core::World& world) override { return new T(actor, world); }
};

typedef std::shared_ptr<Action> ActionPtr;

} // namespace Core::Actions

#endif