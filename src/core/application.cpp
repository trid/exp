#include "application.h"

namespace Core {

void Application::update() {

}

void Application::finish() { _running = false; }

bool Application::isRunning() const { return _running; }

} // namespace Core
