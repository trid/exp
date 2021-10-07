#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <vector>

#include "widget.h"

#include "SDL2/SDL_ttf.h"

namespace View {
class ViewFacade;
} // namespace View

namespace View::Widgets {

class UIManager {
public:
    UIManager();

    void draw(ViewFacade& view);
    void addWidget(WidgetPtr widget);

    [[nodiscard]] TTF_Font* getFont() const { return font; };

    [[nodiscard]] TTF_Font* getConsoleFont() const { return logFont; };

private:
    std::vector<WidgetPtr> widgets;

    TTF_Font* font;
    TTF_Font* logFont;
};

} // namespace View::Widgets

#endif // UI_MANAGER_H