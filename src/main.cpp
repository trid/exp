#define SDL_MAIN_HANDLED

#include <iostream>

#include "application.h"
#include "view/view.h"
#include "world.h"
#include "ai/state_manager.h"
#include "script_manager.h"
#include "system_event_manager.h"
#include "settings.h"
#include "location_type_manager.h"

using namespace std;


int main(int argc, char* argv[]) {
    Application app{};
    ScriptManager scriptManager{};
    Settings settings{scriptManager};
    View view{settings};
    World world(view, app);
    StateManager stateManager{scriptManager, world};
    SystemEventManager systemEventManager{app, view};

    stateManager.registerScriptedStates();
    scriptManager.loadScript("scripts/init.lua");

    while (app.isRunning()) {
        app.update();
        systemEventManager.process();
        view.draw();
    }
    return 0;
}
