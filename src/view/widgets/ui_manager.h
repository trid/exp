#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <vector>

#include "widget.h"

#include "SDL2/SDL_ttf.h"

class View;

class UIManager {
public:
    UIManager();

    void draw(View& view);
    void addWidget(WidgetPtr widget);
    [[nodiscard]] TTF_Font* getFont() const { return font; };
    [[nodiscard]] TTF_Font* getConsoleFont() const { return logFont; };

private:
    std::vector<WidgetPtr> widgets;

    TTF_Font* font;
    TTF_Font* logFont;
};

#endif // UI_MANAGER_H