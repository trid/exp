#include <list>
#include <SDL_timer.h>

#include "process.h"

class Application {
private:
    Application(): lastTime(SDL_GetTicks()) {};

    bool running = true;
    std::list<ProcessPtr> processes;

    int lastTime;
public:
    static Application& getInstance() {
        static Application application;
        return application;
    }

    void finish() { running = false; }
    bool isRunning() { return running; }
    void update();
    void addProcess(ProcessPtr ptr) { processes.push_back(ptr); }
};