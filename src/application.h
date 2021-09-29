#ifndef APPLICATION_H
#define APPLICATION_H

#include <list>
#include <SDL2/SDL_timer.h>

#include "process.h"

class Application {
public:
    Application();

    void finish();
    bool isRunning() const;
    void update();
    void addProcess(ProcessPtr ptr);

private:
    bool running = true;
    std::list<ProcessPtr> processes;

    int lastTime;
};

#endif // APPLICATION_H