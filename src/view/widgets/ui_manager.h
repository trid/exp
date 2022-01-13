#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <vector>

#include "button.h"
#include "widget.h"

#include "../fonts_cache.h"

namespace View {
class ViewFacade;
} // namespace View

namespace View::Widgets {

class UIManager {
public:
    UIManager();

    void draw(Window& window);
    void addWidget(WidgetPtr widget);
    void addButton(ButtonPtr button);

    void onMouseButtonDown(unsigned int x, unsigned int y, unsigned int button);

    FontsCache& getFontsCache();
private:
    std::vector<WidgetPtr> _widgets;
    std::vector<ClickablePtr> _clickables;

    FontsCache _fontsCache;
};

} // namespace View::Widgets

#endif // UI_MANAGER_H