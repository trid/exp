#define SDL_MAIN_HANDLED

#include <iostream>

#include "application.h"
#include "location_type_manager.h"
#include "script_manager.h"
#include "settings.h"
#include "system_event_manager.h"
#include "world.h"

#include "ai/state_manager.h"

#include "view/view.h"
#include "view/widgets/gui_panel.h"

using namespace std;


int main(int argc, char* argv[]) {
    Application app{};
    ScriptManager scriptManager{};
    Settings settings{scriptManager};
    View view{settings};
    World world(view, app);
    StateManager stateManager{scriptManager, world};
    GUIPanel panel{world, view};
    SystemEventManager systemEventManager{app, panel};

    stateManager.registerScriptedStates();
    scriptManager.loadScript("scripts/init.lua");

    while (app.isRunning()) {
        app.update();
        systemEventManager.process();
        view.draw();
    }
    return 0;
}
