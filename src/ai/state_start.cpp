#include "state_start.h"

#include "actor.h"
#include "state_manager.h"
#include "../world.h"

void StateStart::execute(Actor *actor) {
    if (_world.getWood() < 300) {
        actor->say("What shall I do now...");
        actor->setState(getStateManager().getState("StateWoodcutterInRoute"));
        actor->setTargetPosition("forest");
        _world.moveActor(actor, "forest");
    }
    else {
        actor->say("I can rest!");
        actor->setState(getStateManager().getState("StateWoodcutterInRoute"));
        actor->setTargetPosition("home");
        _world.moveActor(actor, "home");
    }
}

void StateStart::processMessage(Actor *actor, Message &message) {

}

StateStart::StateStart(StateManager& stateManager, World& world):
    State(stateManager),
    _world(world)
{

}
