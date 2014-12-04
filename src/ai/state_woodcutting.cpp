#include "state_manager.h"
#include "state_woodcutting.h"
#include "../world.h"

void StateWoodcutting::execute(Actor *actor) {
    actor->say("Cutting wood! Loving wood! Just like my wife!");

    if (actor->getInventory() == actor->getInventoryLimit()) {
        actor->say("Inventory is too heavy. Returning home");
        World::getWorld().moveActor(actor, "home");
        actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
    }

    if (World::getWorld().getWood() >= 300) {
        World::getWorld().moveActor(actor, "home");
        actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
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
    World::getWorld().doAction(actor, "cut_wood");
}