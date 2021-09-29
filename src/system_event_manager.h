#include "application.h"

class View;

class SystemEventManager{
public:
    SystemEventManager(Application& application, View& view);

    void process();

private:
    Application& _application;
    View& _view;
};
