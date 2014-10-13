#include <list>
#include <SDL_ttf.h>
#include "widget.h"

using std::list;

class UIManager {
private:
    UIManager();

    list<WidgetPtr> widgets;

    TTF_Font* font;
    TTF_Font* logFont;
public:
    static UIManager& getInstance() {
        static UIManager uiManager;
        return uiManager;
    }

    void draw();
    void addWidget(Widget* widget);
    TTF_Font* getFont() { return font; };
    TTF_Font* getConsoleFont() { return logFont; };
};