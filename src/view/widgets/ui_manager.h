#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <vector>

#include "widget.h"

#include "SDL2/SDL_ttf.h"
#include "../fonts_cache.h"

namespace View {
class ViewFacade;
} // namespace View

namespace View::Widgets {

class UIManager {
public:
    UIManager();

    void draw(ViewFacade& view);
    void addWidget(WidgetPtr widget);

    FontsCache& getFontsCache();
private:
    std::vector<WidgetPtr> widgets;

    FontsCache _fontsCache;
};

} // namespace View::Widgets

#endif // UI_MANAGER_H