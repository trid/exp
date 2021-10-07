#include "state_finished.h"

#include "constants.h"
#include "state.h"

void StateFinished::processMessage(Actor *actor, Core::Message &message) {

}

StateFinished::StateFinished(StateManager& stateManager) : State(stateManager) {}

void StateFinished::enter(Actor* actor) { actor->say(kStateFinishedEnterMessage); }

void StateFinished::execute(Actor* actor) { actor->say(kStateFinishedExecuteMessage); }

void StateFinished::exit(Actor* actor) { actor->say(kStateFinishedExitMessage); }
