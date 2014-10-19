#include "application.h"

void Application::update() {
    int currentTime = SDL_GetTicks();
    int delta = currentTime - lastTime;
    lastTime = currentTime;
    for (ProcessPtr process: processes) {
        process->update(delta);
    }
    processes.remove_if([](ProcessPtr processPtr) { return processPtr->finished(); });
}
