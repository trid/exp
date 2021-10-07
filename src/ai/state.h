#ifndef STATE_H
#define STATE_H

#include <memory>
#include "boost/optional.hpp"

namespace Core {
class Message;
} // namespace Core

namespace Core::AI {

class Actor;
class StateManager;

class State {
public:
    explicit State(StateManager& stateManager);

    virtual void enter(Actor *) = 0;
    virtual void execute(Actor *) = 0;
    virtual void exit(Actor *) = 0;
    virtual void processMessage(Actor *actor, Core::Message &message) = 0;

protected:
    StateManager& getStateManager();

private:
    StateManager& _stateManager;
};

using StateUPtr = std::unique_ptr<State>;
using StateOpt = boost::optional<State&>;

} // namespace Core::AI

#endif // STATE_H