#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "map_object_view.h"
#include "ui_manager.h"
#include "ui_message_manager.h"
#include "../settings.h"

using std::list;
using std::string;

class Label;
class LogView;
class ActorView;

class WoodUpdaterListener: public IUIMessageListener {
private:
    Label* label;
public:
    WoodUpdaterListener(Label* label): label(label){}
    virtual bool listen(UIMessageData const &messageData);
};

class FoodUpdaterListener: public IUIMessageListener {
private:
    Label* label;
public:
    FoodUpdaterListener(Label* label): label(label){}
    virtual bool listen(UIMessageData const &messageData);
};

class View {
public:
    explicit View(const Settings& settings);

    void draw();
    SDL_Renderer* getRenderer() { return renderer; }

    void addMessage(const string& message);

    int getWindowWidth() const { return windowWidth; }
    int getWindowHeight() const { return windowHeight; }
    Uint32 getScreenPixelFormat();
    void showNextAgent();
    void showPrevAgent();

    IUIMessageListener* woodUpdater;
    IUIMessageListener* foodUpdater;
private:
    int windowWidth;
    int windowHeight;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* background;
    SDL_Texture* actor;

    Label* foodLabel;
    Label* woodLabel;
    LogView* logView;
    ActorView* actorView;

    list <MapObjectPtr> mapObjects;

    UIManager _uiManager;
};

#endif