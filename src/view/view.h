#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "map_object_view.h"
#include "widgets/ui_manager.h"
#include "widgets/ui_message_manager.h"
#include "../settings.h"

using std::list;
using std::string;

class Label;
class LogView;
class ActorView;

class View {
public:
    explicit View(const Settings& settings);

    void draw();
    SDL_Renderer* getRenderer() { return renderer; }

    int getWindowWidth() const { return windowWidth; }
    int getWindowHeight() const { return windowHeight; }
    Uint32 getScreenPixelFormat();

    UIManager& getUiManager();
    UIMessageManager& getUIMessageManager();
private:
    int windowWidth;
    int windowHeight;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* background;
    SDL_Texture* actor;

    list <MapObjectPtr> mapObjects;

    UIManager _uiManager;
    UIMessageManager _uiMessageManager;
};

#endif