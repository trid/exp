#include "state_manager.h"
#include "state_woodcutting.h"
#include "../world.h"

void StateWoodcutting::execute(Actor *actor) {
    actor->say("Cutting wood! Loving wood! Just like my wife!");

    if (actor->getInventory() == actor->getInventoryLimit()) {
        actor->say("Inventory is too heavy. Returning home");
        _world.moveActor(actor, "home");
        actor->setState(getStateManager().getState("StateWoodcutterInRoute"));
    }

    if (_world.getWood() >= 300) {
        _world.moveActor(actor, "home");
        actor->setState(getStateManager().getState("StateWoodcutterInRoute"));
    }
}

void StateWoodcutting::processMessage(Actor *actor, Message &message) {

}

void StateWoodcutting::exit(Actor* actor) {
    actor->say("Finished cutting wood");
    actor->removeAction();
}

void StateWoodcutting::enter(Actor* actor) {
    actor->say("Start cutting wood");
    _world.doAction(actor, "cut_wood");
}

StateWoodcutting::StateWoodcutting(StateManager& stateManager, World& world):
    State(stateManager),
    _world(world) {}
