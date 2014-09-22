#include "state_woodcutting.h"
#include "state_moving.h"
#include "state_finished.h"
#include "world.h"

void StateWoodcutting::execute(Actor *actor) {
    cout << "Cutting wood" << endl;
    World::getWorld().addWood();

    if (actor->getWater() == 0) {
        cout << "Thirsty. Going to drink something." << endl;
        actor->setTargetPosition(POSITION_HOME);
        actor->setState(StateMoving::getInstance());
    }
    if (World::getWorld().getWood() > 300) {
        actor->setState(StateFinished::getInstance());
    }
}
