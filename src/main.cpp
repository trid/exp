#define SDL_MAIN_HANDLED

#include <iostream>

#include "application.h"
#include "constants.h"
#include "location_type_manager.h"
#include "settings.h"
#include "system_event_manager.h"
#include "world.h"

#include "ai/state_manager.h"
#include "ai/behaviour_processor.h"

#include "scripting/main_script_context.h"

#include "view/view_facade.h"
#include "view/widgets/gui_panel.h"

using namespace std;


int main(int argc, char* argv[]) {
    Core::Application app{};
    Core::Settings settings{};
    View::ViewFacade view{settings};
    Core::World world(view, app);
    Core::AI::StateManager stateManager{world};
    View::Widgets::GUIPanel panel{world, view};
    Core::SystemEventManager systemEventManager{app, panel};
    Scripting::MainScriptContext scriptContext{world, stateManager};
    Core::AI::BehaviourProcessor behaviourProcessor{stateManager, world.getActorsRegistry().getActors()};

    scriptContext.loadScript(Core::kInitScriptPath);

    app.addProcess(std::make_shared<Core::AI::BehaviourProcessorProcess>(behaviourProcessor));

    while (app.isRunning()) {
        app.update();
        systemEventManager.process();
        view.draw();
    }
    return 0;
}
