#include "state_start.h"

#include "actor.h"
#include "state_manager.h"
#include "../world.h"

void StateStart::execute(Actor *actor) {
    if (World::getWorld().getWood() < 300) {
        actor->say("What shall I do now...");
        actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
        actor->setTargetPosition("forest");
        World::getWorld().moveActor(actor, "forest");
    }
    else {
        actor->say("I can rest!");
        actor->setState(StateManager::getInstance().getState("StateWoodcutterInRoute"));
        actor->setTargetPosition("home");
        World::getWorld().moveActor(actor, "home");
    }
}

void StateStart::processMessage(Actor *actor, Message &message) {

}
