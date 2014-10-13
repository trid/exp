#include <SDL_events.h>
#include "system_event_manager.h"
#include "application.h"
#include "view/view.h"

void SystemEventManager::process() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            Application::getInstance().finish();
        }
        if (e.type == SDL_KEYUP) {
            if (e.key.keysym.sym == SDLK_LEFT) {
                View::getView().showPrevAgent();
            }
            if (e.key.keysym.sym == SDLK_RIGHT) {
                View::getView().showNextAgent();
            }
        }
    }
}
