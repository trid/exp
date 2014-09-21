#include "state_woodcutting.h"
#include "state_moving.h"
#include "state_finished.h"

void StateWoodcutting::execute(Actor *actor) {
    cout << "Cutting wood" << endl;
    actor->cutWood();

    if (actor->getWater() == 0) {
        cout << "Thirsty. Going to drink something." << endl;
        actor->setTargetPosition(POSITION_HOME);
        actor->setState(StateMoving::getInstance());
    }
    if (actor->getWood() > 300) {
        actor->setState(StateFinished::getInstance());
    }
}
