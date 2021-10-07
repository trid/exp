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
#include "ui_message_manager.h"
#include "../settings.h"

class Label;
class LogView;
class ActorView;

namespace View {

class ViewFacade {
public:
    explicit ViewFacade(const Core::Settings& settings);

    Widgets::UIManager& getUiManager();
    UIMessageManager& getUIMessageManager();

    Uint32 getScreenPixelFormat();

    void draw();

    Window& getWindow();
private:
    Window _window;

    SDL_Texture* background;
    SDL_Texture* actor;

    std::list <MapObjectPtr> mapObjects;

    Widgets::UIManager _uiManager;
    UIMessageManager _uiMessageManager;
};

} // View

#endif