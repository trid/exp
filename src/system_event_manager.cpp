#include <SDL2/SDL_events.h>
#include "system_event_manager.h"
#include "application.h"
#include "view/view.h"

void SystemEventManager::process() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            _application.finish();
        }
        if (e.type == SDL_KEYUP) {
            if (e.key.keysym.sym == SDLK_LEFT) {
                _guiPanel.showPrevAgent();
            }
            if (e.key.keysym.sym == SDLK_RIGHT) {
                _guiPanel.showNextAgent();
            }
        }
    }
}

SystemEventManager::SystemEventManager(Application& application, GUIPanel& guiPanel):
        _application(application),
        _guiPanel(guiPanel){}
