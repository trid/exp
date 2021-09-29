#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <list>
#include <SDL2/SDL_ttf.h>
#include "widget.h"


using std::list;

class View;

class UIManager {
public:
    UIManager();

    void draw(View& view);
    void addWidget(Widget* widget);
    TTF_Font* getFont() { return font; };
    TTF_Font* getConsoleFont() { return logFont; };

private:
    list<WidgetPtr> widgets;

    TTF_Font* font;
    TTF_Font* logFont;
};

#endif // UI_MANAGER_H