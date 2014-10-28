#include "state_start.h"

#include "actor.h"
#include "state_manager.h"
#include "../world.h"

void StateStart::execute(Actor *actor) {
    actor->say("What shall I do now...");
    actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
    actor->setTargetPosition("forest");
    World::getWorld().moveActor(actor, "forest");
}

void StateStart::processMessage(Actor *actor, Message &message) {

}
