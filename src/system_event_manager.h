class SystemEventManager{
public:
    static SystemEventManager& getInstance() {
        static SystemEventManager systemEventManager;
        return systemEventManager;
    }

    void process();
};
