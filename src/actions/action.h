#ifndef ACTION_H
#define ACTION_H

#include <memory>

using std::shared_ptr;

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Actors {
class Actor;
} // namespace Core::AI

namespace Core::Actions {

class Action {
private:
    bool running = true;
protected:
    AI::Actors::Actor* actor;
public:
    virtual bool isValid() = 0;
    virtual void update(int delta) = 0;
    virtual int progress() = 0;
    virtual bool isFinished() = 0;

    [[nodiscard]] bool isRunning() const;

    void stop();

    AI::Actors::Actor* getActor();

    Action(AI::Actors::Actor* actor, Core::World&);
};

class VirtualActionFactory {
public:
    virtual Action* createAction(AI::Actors::Actor* actor, Core::World& world) = 0;
};

template<class T>
class ActionFactory : public VirtualActionFactory {
    Action* createAction(AI::Actors::Actor* actor, Core::World& world) override { return new T(actor, world); }
};

typedef shared_ptr<Action> ActionPtr;

} // namespace Core::Actions

#endif