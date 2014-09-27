class Application {
private:
    bool running = true;
public:
    static Application& getInstance() {
        static Application application;
        return application;
    }

    void finish() { running = false; }
    bool isRunning() { return running; }
    void process() {}
};