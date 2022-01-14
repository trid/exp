#define SDL_MAIN_HANDLED

#include "application.h"
#include "constants.h"
#include "location_type.h"
#include "settings.h"
#include "system_event_manager.h"
#include "timed_process_controller.h"
#include "world.h"

#include "../ai/state_manager.h"
#include "../ai/behaviour_processor.h"

#include "../scripting/main_script_context.h"

#include "../view/view_facade.h"

using namespace std;


int main(int argc, char* argv[]) {
    Core::Application app{};
    Core::Timer timer;
    Core::TimedProcessController timedProcessController{timer};
    Core::Settings settings{};
    Core::GlobalMessageBus messageManager;
    Core::WorldMap worldMap;
    Core::World world(timedProcessController, messageManager, worldMap);
    Core::AI::StateManager stateManager{};
    Scripting::MainScriptContext scriptContext{world, stateManager};
    scriptContext.loadScript(Core::kInitScriptPath);
    View::ViewFacade view{settings, messageManager, world, timer};
    Core::SystemEventManager systemEventManager{app, view.getUIManager(), view.getGUIPanel()};
    Core::AI::BehaviourProcessor behaviourProcessor{stateManager, world};

    timedProcessController.addProcess(std::make_shared<Core::AI::BehaviourProcessorProcess>(behaviourProcessor));

    while (app.isRunning()) {
        app.update();
        timedProcessController.update();
        systemEventManager.process();
        view.draw();
    }
    return 0;
}
