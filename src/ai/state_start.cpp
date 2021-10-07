#include "state_start.h"

#include "constants.h"
#include "state_manager.h"
#include "../world.h"

namespace Core::AI {

void StateStart::execute(Actor* actor) {
    if (_world.getWood() < 300) {
        actor->say(kStateStartExecuteWorkMessage);
        actor->setState(getStateManager().getState(kStateWoodcutterInRoute));
        actor->setTargetPosition(kForestLocationName);
        _world.moveActor(actor, kForestLocationName);
    } else {
        actor->say(kStateStartExecuteRestMessage);
        actor->setState(getStateManager().getState(kStateWoodcutterInRoute));
        actor->setTargetPosition(kHomeLocationName);
        _world.moveActor(actor, kHomeLocationName);
    }
}

void StateStart::processMessage(Actor* actor, Core::Message& message) {

}

StateStart::StateStart(StateManager& stateManager, Core::World& world) :
        State(stateManager),
        _world(world) {

}

void StateStart::enter(Actor* actor) { actor->say(kStateStartEnterMessage); }

void StateStart::exit(Actor* actor) { actor->say(kStateStartExitMessage); }

} // namespace Core::AI