#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "map_object_view.h"
#include "window.h"
#include "widgets/ui_manager.h"
#include "../global_message_manager.h"
#include "../settings.h"
#include "scene_object_manager.h"

class Label;
class LogView;
class ActorView;

namespace Core {
class World;
}

namespace View {

class ViewFacade {
public:
    explicit ViewFacade(const Core::Settings& settings, Core::GlobalMessageManager& globalMessageManager, Core::World& world);

    Widgets::UIManager& getUiManager();
    Core::GlobalMessageManager& getUIMessageManager();

    Uint32 getScreenPixelFormat();

    void draw();

    Window& getWindow();
private:
    Window _window;

    SDL_Texture* background;
    SDL_Texture* actor;

    Widgets::UIManager _uiManager;
    Core::GlobalMessageManager& _globalMessageManager;
    SceneObjectManager _sceneObjectManager;
};

} // View

#endif