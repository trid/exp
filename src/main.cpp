#define SDL_MAIN_HANDLED

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

using namespace std;


int main(int argc, char* argv[]) {
    Core::Application app{};
    Core::Settings settings{};
    Core::GlobalMessageManager messageManager;
    Core::World world(app, messageManager);
    Core::AI::StateManager stateManager{world};
    Scripting::MainScriptContext scriptContext{world, stateManager};
    scriptContext.loadScript(Core::kInitScriptPath);
    View::ViewFacade view{settings, messageManager, world};
    Core::SystemEventManager systemEventManager{app, view.getGUIPanel()};
    Core::AI::BehaviourProcessor behaviourProcessor{stateManager, world.getAgentsRegistry().getActors()};

    app.addProcess(std::make_shared<Core::AI::BehaviourProcessorProcess>(behaviourProcessor));

    while (app.isRunning()) {
        app.update();
        systemEventManager.process();
        view.draw();
    }
    return 0;
}
