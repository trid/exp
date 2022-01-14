#ifndef VIEW_FACADE_H
#define VIEW_FACADE_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../core/global_message_bus.h"
#include "../core/settings.h"

#include "image.h"
#include "map_object_view.h"
#include "scene_object_renderer.h"
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
    explicit ViewFacade(const Core::Settings& settings, Core::GlobalMessageBus& globalMessageManager,
                        Core::World& world,
                        Core::Timer& timer);

    Core::GlobalMessageBus& getUIMessageManager();

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
    Core::GlobalMessageBus& _globalMessageManager;
    Widgets::GUIPanel _guiPanel;
    Widgets::SpeedControlPanel _speedControlPanel;
    SceneObjectRenderer _sceneObjectManager;
    const Core::AI::Agents::AgentsRegistry& _agentsRegistry;
};

} // View

#endif // VIEW_FACADE_H