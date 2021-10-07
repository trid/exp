#define SDL_MAIN_HANDLED

#include <iostream>

#include "application.h"
#include "constants.h"
#include "location_type_manager.h"
#include "scripting/main_script_context.h"
#include "settings.h"
#include "system_event_manager.h"
#include "world.h"

#include "ai/state_manager.h"

#include "view/view.h"
#include "view/widgets/gui_panel.h"

using namespace std;


int main(int argc, char* argv[]) {
    Core::Application app{};
    Core::Settings settings{};
    MainScriptContext scriptContext{};
    View view{settings};
    Core::World world(view, app);
    StateManager stateManager{scriptContext, world};
    GUIPanel panel{world, view};
    Core::SystemEventManager systemEventManager{app, panel};

    stateManager.registerScriptedStates();
    scriptContext.loadScript(Core::kInitScriptPath);

    while (app.isRunning()) {
        app.update();
        systemEventManager.process();
        view.draw();
    }
    return 0;
}
