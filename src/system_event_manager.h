#include "application.h"
#include "view/widgets/gui_panel.h"


namespace Core {

class SystemEventManager {
public:
    SystemEventManager(Application& application, GUIPanel& guiPanel);

    void process();

private:
    Application& _application;
    GUIPanel& _guiPanel;
};

} // namespace Core