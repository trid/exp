#ifndef ACTION_H
#define ACTION_H

#include <memory>

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Agents {
class Agent;
} // namespace Core::AI

namespace Core::Actions {

class Action {
public:
    Action(AI::Agents::Agent& actor, Core::World&);

    [[nodiscard]] virtual bool isValid() const = 0;
    virtual void update(int delta) = 0;
    virtual int progress() = 0;
    [[nodiscard]] virtual bool isFinished() const = 0;

    [[nodiscard]] bool isRunning() const;

    void stop();

    AI::Agents::Agent& getActor();

private:
    bool _running = true;

protected:
    AI::Agents::Agent& _actor;
};

class VirtualActionFactory {
public:
    virtual Action* createAction(AI::Agents::Agent& actor, Core::World& world) = 0;
};

template<class T>
class ActionFactory : public VirtualActionFactory {
    Action* createAction(AI::Agents::Agent& actor, Core::World& world) override { return new T(actor, world); }
};

typedef std::shared_ptr<Action> ActionPtr;

} // namespace Core::Actions

#endif