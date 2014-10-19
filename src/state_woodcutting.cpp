#include "state_manager.h"
#include "state_woodcutting.h"
#include "world.h"

void StateWoodcutting::execute(Actor *actor) {
    if (actor->getPosition() == "forest") {
        actor->say("Cutting wood! Loving wood! Just like my wife!");
        actor->addItem();
    }
    else {
        actor->say("Can't cut wood when not in forest");
    }

    if (actor->getWater() == 0) {
        actor->say("Thirsty. Going to drink something.");
        World::getWorld().moveActor(actor, "home");
        actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
    } else {
        if (actor->getFood() == 0) {
            actor->say("Hungry. Going to eat something.");
            World::getWorld().moveActor(actor, "home");
            actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
        } else {
            if (actor->getInventory() == actor->getInventoryLimit()) {
                actor->say("Inventory is too heavy. Returning home");
                World::getWorld().moveActor(actor, "home");
                actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
            }
        }
    }

    if (World::getWorld().getWood() > 300) {
        actor->setState(StateManager::getInstance().getState("StateFinished"));
    }
}

void StateWoodcutting::processMessage(Actor *actor, Message &message) {

}
