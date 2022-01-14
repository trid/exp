#ifndef VIEW_FACADE_H
#define VIEW_FACADE_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../core/global_message_manager.h"
#include "../core/settings.h"

#include "image.h"
#include "map_object_view.h"
#include "scene_object_manager.h"
#include "window.h"
#include "widgets/gui_panel.h"
#include "widgets/speed_control_panel.h"
#include "widgets/ui_manager.h"


namespace Core {
class Timer;
class World;
}

namespace View {

class ViewFacade {
public:
    explicit ViewFacade(const Core::Settings& settings, Core::GlobalMessageManager& globalMessageManager,
                        Core::World& world,
                        Core::Timer& timer);

    Core::GlobalMessageManager& getUIMessageManager();

    Uint32 getScreenPixelFormat() const;

    void draw();

    Window& getWindow();

    View::Widgets::UIManager& getUIManager();
    View::Widgets::GUIPanel& getGUIPanel();

private:
    Window _window;

    Image _background;
    std::unordered_map<std::string, Image> _actors;

    Widgets::UIManager _uiManager;
    Core::GlobalMessageManager& _globalMessageManager;
    Widgets::GUIPanel _guiPanel;
    Widgets::SpeedControlPanel _speedControlPanel;
    SceneObjectManager _sceneObjectManager;
    const Core::AI::Actors::AgentsRegistry& _agentsRegistry;
};

} // View

#endif // VIEW_FACADE_H