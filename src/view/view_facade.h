#ifndef VIEW_FACADE_H
#define VIEW_FACADE_H

#include <list>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "image.h"
#include "map_object_view.h"
#include "scene_object_manager.h"
#include "window.h"
#include "widgets/gui_panel.h"
#include "widgets/ui_manager.h"

#include "../global_message_manager.h"
#include "../settings.h"

class Label;

class LogView;

class ActorView;

namespace Core {
class World;
}

namespace View {

class ViewFacade {
public:
    explicit ViewFacade(const Core::Settings& settings, Core::GlobalMessageManager& globalMessageManager,
                        Core::World& world);

    Core::GlobalMessageManager& getUIMessageManager();

    Uint32 getScreenPixelFormat() const;

    void draw();

    Window& getWindow();

    View::Widgets::GUIPanel& getGUIPanel();

private:
    Window _window;

    Image _background;
    Image _actor;

    Widgets::UIManager _uiManager;
    Core::GlobalMessageManager& _globalMessageManager;
    Widgets::GUIPanel _guiPanel;
    SceneObjectManager _sceneObjectManager;
    const Core::AI::Actors::AgentsRegistry& _agentsRegistry;
};

} // View

#endif // VIEW_FACADE_H