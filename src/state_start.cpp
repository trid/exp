#include "state_start.h"

#include "actor.h"
#include "state_moving.h"

void StateStart::execute(Actor *actor) {
    cout << "What shall I do now..." << endl;
    actor->setState(StateMoving::getInstance());
    actor->setTargetPosition(POSITION_FOREST);
}