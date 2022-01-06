#ifndef APPLICATION_H
#define APPLICATION_H

#include <list>

namespace Core {

class Application {
public:
    Application();

    void finish();

    bool isRunning() const;

    void update();

private:
    bool running = true;
};

} // namespace Core

#endif // APPLICATION_H