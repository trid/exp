#include "../view_facade.h"

#include "constants.h"
#include "ui_manager.h"


namespace View::Widgets {

UIManager::UIManager() {

}

void UIManager::draw(Window& window) {
    for (WidgetPtr widgetPtr: widgets) {
        widgetPtr->draw(window);
    }
}

void UIManager::addWidget(WidgetPtr widget) {
    widgets.push_back(WidgetPtr(widget));
}

FontsCache& UIManager::getFontsCache() {
    return _fontsCache;
}

} // namespace View::Widgets