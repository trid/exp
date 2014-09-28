#include "actor.h"
#include "state_moving.h"
#include "state_manager.h"

void StateMoving::execute(Actor *actor) {
    cout << "On road" << endl;
    actor->updateSteps();

    if (actor->getTargetPosition() == "home") {
        if (actor->getPosition() == "forest" && actor->getSteps() == 3) {
            cout << "Came home. Going to drink something." << endl;
            actor->setTargetPosition("well");
            actor->setPosition("home");
            actor->resetSteps();
        } else {
            if (actor->getPosition() == "well" && actor->getSteps() == 2) {
                actor->setTargetPosition("forest");
                actor->setPosition("home");
                actor->resetSteps();
            }
        }
    }
    else {
        if (actor->getTargetPosition() == "forest") {
            if (actor->getSteps() == 3) {
                cout << "Came to forest" << endl;
                actor->setState(StateManager::getInstance().getState("StateWoodcutting"));
                actor->setPosition("forest");
                actor->resetSteps();
            }
        } else {
            if (actor->getTargetPosition() == "well") {
                if (actor->getSteps() == 2) {
                    cout << "Came to well. Drinking." << endl;
                    actor->drink();
                    actor->setPosition("well");
                    actor->setTargetPosition("home");
                    actor->resetSteps();
                }
            }
        }
    }
}

void StateMoving::enter(Actor *actor) {
    cout << "Start moving" << endl;
    actor->resetSteps();
}
