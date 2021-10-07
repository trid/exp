#include "application.h"

namespace Core {

void Application::update() {
    int currentTime = SDL_GetTicks();
    int delta = currentTime - lastTime;
    lastTime = currentTime;
    for (ProcessPtr process: processes) {
        process->update(delta);
    }
    processes.remove_if([](ProcessPtr processPtr) { return processPtr->finished(); });
}

Application::Application() : lastTime(SDL_GetTicks()) {}

void Application::finish() { running = false; }

bool Application::isRunning() const { return running; }

void Application::addProcess(ProcessPtr ptr) { processes.push_back(ptr); }

} // namespace Core
