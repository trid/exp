#include <iostream>

#include "application.h"
#include "view/view.h"
#include "world.h"
#include "ai/state_manager.h"
#include "script_manager.h"
#include "system_event_manager.h"
#include "settings.h"
#include "parameter.h"

using namespace std;


int main(int argc, char* argv[]) {
    Application& app = Application::getInstance();
    View& view = View::getView();
    ScriptManager& scriptManager = ScriptManager::getInstance();
    StateManager& stateManager = StateManager::getInstance();
    SystemEventManager& systemEventManager = SystemEventManager::getInstance();
    Settings& settings = Settings::getSettings();
    stateManager.registerScriptedStates();
    scriptManager.loadScript("scripts/init.lua");

    while (app.isRunning()) {
        app.update();
        systemEventManager.process();
        view.draw();
    }
    return 0;
}
