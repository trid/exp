#ifndef APPLICATION_H
#define APPLICATION_H

namespace Core {

class Application {
public:
    void finish();

    [[nodiscard]] bool isRunning() const;

    void update();

private:
    bool _running = true;
};

} // namespace Core

#endif // APPLICATION_H