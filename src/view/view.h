#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "label.h"
#include "map_object.h"

using std::list;
using std::string;

class View {
public:
    static View& getView() {
        static View view;
        return view;
    };

    void draw();
    SDL_Renderer* getRenderer() { return renderer; }
    void registerMapObject(int x, int y, const string& path);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* background;
    SDL_Texture* home;
    SDL_Texture* forest;
    SDL_Texture* well;
    SDL_Texture* actor;

    Label* foodLabel;
    Label* woodLabel;

    list <MapObjectPtr> mapObjects;

    View();

    void updateLabels();
};

#endif