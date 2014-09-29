#include "state_manager.h"
#include "state_woodcutting.h"
#include "world.h"

void StateWoodcutting::execute(Actor *actor) {
    cout << "Cutting wood! Loving wood! Just like my wife!" << endl;
    World::getWorld().addWood();

    if (actor->getWater() == 0) {
        cout << "Thirsty. Going to drink something." << endl;
        World::getWorld().moveActor(actor, "home", 3);
        actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
    }
    if (World::getWorld().getWood() > 300) {
        actor->setState(StateManager::getInstance().getState("StateFinished"));
    }
}

void StateWoodcutting::processMessage(Actor *actor, Message &message) {

}
