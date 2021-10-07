#ifndef ACTION_H
#define ACTION_H

#include <memory>

using std::shared_ptr;

class Actor;

namespace Core {
class World;
} // namespace Core

namespace Core::Actions {

class Action {
private:
    bool running = true;
protected:
    Actor* actor;
public:
    virtual bool isValid() = 0;
    virtual void update(int delta) = 0;
    virtual int progress() = 0;
    virtual bool isFinished() = 0;

    [[nodiscard]] bool isRunning() const;

    void stop();

    Actor* getActor();

    Action(Actor* actor, Core::World&);
};

class VirtualActionFactory {
public:
    virtual Action* createAction(Actor* actor, Core::World& world) = 0;
};

template<class T>
class ActionFactory : public VirtualActionFactory {
    virtual Action* createAction(Actor* actor, Core::World& world) override { return new T(actor, world); }
};

typedef shared_ptr<Action> ActionPtr;

} // namespace Core::Actions

#endif