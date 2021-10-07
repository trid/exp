#include "state_woodcutting.h"

#include "../actions/constants.h"
#include "../world.h"

#include "constants.h"
#include "state_manager.h"

void StateWoodcutting::execute(Actor *actor) {
    actor->say(kStateWoodcuttingExecuteMessage);

    if (actor->getInventory() == actor->getInventoryLimit()) {
        actor->say(kInventoryIsFullMessage);
        _world.moveActor(actor, kHomeLocationName);
        actor->setState(getStateManager().getState(kStateWoodcutterInRoute));
    }

    if (_world.getWood() >= 300) {
        _world.moveActor(actor, kHomeLocationName);
        actor->setState(getStateManager().getState(kStateWoodcutterInRoute));
    }
}

void StateWoodcutting::processMessage(Actor *actor, Core::Message &message) {

}

void StateWoodcutting::exit(Actor* actor) {
    actor->say(kStateWoodcuttingExitMessage);
    actor->removeAction();
}

void StateWoodcutting::enter(Actor* actor) {
    actor->say(kStateWoodcuttingEnterMessage);
    _world.doAction(actor, kActionCutWood);
}

StateWoodcutting::StateWoodcutting(StateManager& stateManager, Core::World& world):
    State(stateManager),
    _world(world) {}
