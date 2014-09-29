#include "state_start.h"

#include "actor.h"
#include "state_manager.h"
#include "world.h"

void StateStart::execute(Actor *actor) {
    cout << "What shall I do now..." << endl;
    //actor->setState(StateManager::getInstance().getState("StateMoving"));
    actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
    actor->setTargetPosition("forest");
    World::getWorld().moveActor(actor, "forest", 3);
}

void StateStart::processMessage(Actor *actor, Message &message) {

}
