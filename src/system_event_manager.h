#ifndef SYSTEM_EVENT_MANAGER_H
#define SYSTEM_EVENT_MANAGER_H

#include "application.h"
#include "view/widgets/gui_panel.h"


namespace Core {

class SystemEventManager {
public:
    SystemEventManager(Application& application, View::Widgets::GUIPanel& guiPanel);

    void process();

private:
    Application& _application;
    View::Widgets::GUIPanel& _guiPanel;
};

} // namespace Core

#endif // SYSTEM_EVENT_MANAGER_H