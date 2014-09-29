#include <iostream>

#include "actor.h"
#include "application.h"
#include "view.h"
#include "registry.h"
#include "world.h"
#include "state_manager.h"
#include "script_manager.h"
#include "system_event_manager.h"

using namespace std;

int ticksToForest = 3;
int ticksToWater = 5;
Position targetPosition = POSITION_NONE;
int wood = 0;
int neededWood = 300;
int wayPassed = 0;

Application& app = Application::getInstance();

Actor& woodCutter = ActorsRegistry::getRegistry().createActor();
Actor& hunter = ActorsRegistry::getRegistry().createActor();

int process() {
    cout << "Wood: " << World::getWorld().getWood() << endl;
    cout << "Food: " << World::getWorld().getFood() << endl;

    return 0;
}

int main(int argc, char* argv[]) {
    View& view = View::getView();
    World& world = World::getWorld();
    ActorsRegistry &registry = ActorsRegistry::getRegistry();
    ScriptManager& scriptManager = ScriptManager::getInstance();
    StateManager& stateManager = StateManager::getInstance();
    SystemEventManager& systemEventManager = SystemEventManager::getInstance();
    stateManager.registerScriptedStates();
    woodCutter.setPosition("home");
    woodCutter.setState(StateManager::getInstance().getState("StateStart"));
    hunter.setPosition("home");

    hunter.setState(stateManager.getState("StateHunterStart"));

    while (app.isRunning()) {
        process();
        registry.update();
        world.update();
        view.draw();
        systemEventManager.process();
        SDL_Delay(100);
    }
    return 0;
}