#include "state.h"
#include "state_finished.h"

void StateFinished::processMessage(Actor *actor, Message &message) {

}

StateFinished::StateFinished(StateManager& stateManager) : State(stateManager) {}
