#include "application.h"

void Application::update() {
    for (ProcessPtr process: processes) {
        process->update();
    }
    processes.remove_if([](ProcessPtr processPtr) { return processPtr->finished(); });
}
