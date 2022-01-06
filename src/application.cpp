#include "application.h"

namespace Core {

void Application::update() {

}

Application::Application() {}

void Application::finish() { running = false; }

bool Application::isRunning() const { return running; }

} // namespace Core
