#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "map_object.h"

using std::list;
using std::string;

class Label;
class LogView;

class View {
public:
    static View& getView() {
        static View view;
        return view;
    };

    void draw();
    SDL_Renderer* getRenderer() { return renderer; }
    void registerMapObject(int x, int y, const string& path);

    void addMessage(const string& message);

    int getWindowWidth() const { return windowWidth; }
    void setWindowWidth(int windowWidth) { View::windowWidth = windowWidth; }
    int getWindowHeight() const { return windowHeight; }
    void setWindowHeight(int windowHeight) { View::windowHeight = windowHeight; }
    Uint32 getScreenPixelFormat();
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


    list <MapObjectPtr> mapObjects;

    View();

    void updateLabels();
};

#endif