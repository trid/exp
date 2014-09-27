#include <SDL_events.h>
#include "system_event_manager.h"
#include "application.h"

void SystemEventManager::process() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            Application::getInstance().finish();
        }
    }
}
