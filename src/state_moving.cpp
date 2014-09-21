#include "actor.h"
#include "state_moving.h"
#include "state_woodcutting.h"

void StateMoving::execute(Actor *actor) {
    cout << "On road" << endl;
    actor->updateSteps();

    switch (actor->getTargetPosition()) {
        case POSITION_NONE:break;
        case POSITION_HOME:
            if (actor->getPosition() == POSITION_FOREST && actor->getSteps() == 3) {
                cout << "Came home. Going to drink something." << endl;
                actor->setTargetPosition(POSITION_WATER);
                actor->setPosition(POSITION_HOME);
                actor->resetSteps();
            } else {
                if (actor->getPosition() == POSITION_WATER && actor->getSteps() == 2) {
                    actor->setTargetPosition(POSITION_FOREST);
                    actor->setPosition(POSITION_HOME);
                    actor->resetSteps();
                }
            }
            break;
        case POSITION_FOREST:
            if (actor->getSteps() == 3) {
                cout << "Came to forest" << endl;
                actor->setState(StateWoodcutting::getInstance());
                actor->setPosition(POSITION_FOREST);
                actor->resetSteps();
            }
            break;
        case POSITION_WATER:
            if (actor->getSteps() == 2) {
                cout << "Came to well. Drinking." << endl;
                actor->drink();
                actor->setPosition(POSITION_WATER);
                actor->setTargetPosition(POSITION_HOME);
                actor->resetSteps();
            }
            break;
    }
}

void StateMoving::enter(Actor *actor) {
    cout << "Start moving" << endl;
    actor->resetSteps();
}
