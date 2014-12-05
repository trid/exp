#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "map_object_view.h"

using std::list;
using std::string;

class Label;
class LogView;
class ActorView;

class View {
public:
    static View& getView() {
        static View view;
        return view;
    };

    void draw();
    SDL_Renderer* getRenderer() { return renderer; }

    void addMessage(const string& message);

    int getWindowWidth() const { return windowWidth; }
    int getWindowHeight() const { return windowHeight; }
    Uint32 getScreenPixelFormat();
    void showNextAgent();
    void showPrevAgent();
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

    View();

    void updateLabels();
};

#endif