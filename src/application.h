#include <list>

#include "process.h"

class Application {
private:
    bool running = true;
    std::list<ProcessPtr> processes;
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