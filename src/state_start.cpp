#include "state_start.h"

#include "actor.h"
#include "state_manager.h"

void StateStart::execute(Actor *actor) {
    cout << "What shall I do now..." << endl;
    actor->setState(StateManager::getInstance().getState("StateMoving"));
    actor->setTargetPosition("forest");
}