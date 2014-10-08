#include <iostream>
#include <SDL_ttf.h>

#include "actor.h"
#include "application.h"
#include "view/view.h"
#include "registry.h"
#include "world.h"
#include "state_manager.h"
#include "script_manager.h"
#include "system_event_manager.h"
#include "settings.h"

using namespace std;

int ticksToForest = 3;
int ticksToWater = 5;
Position targetPosition = POSITION_NONE;
int wood = 0;
int neededWood = 300;
int wayPassed = 0;


int main(int argc, char* argv[]) {
    Application& app = Application::getInstance();
    View& view = View::getView();
    ScriptManager& scriptManager = ScriptManager::getInstance();
    StateManager& stateManager = StateManager::getInstance();
    SystemEventManager& systemEventManager = SystemEventManager::getInstance();
    Settings& settings = Settings::getSettings();
    stateManager.registerScriptedStates();
    scriptManager.loadScript("scripts/init.lua");
    int delay = settings.getIntParameter("time_delay");

    while (app.isRunning()) {
        app.update();
        systemEventManager.process();
        view.draw();
        SDL_Delay(delay);
    }
    return 0;
}
