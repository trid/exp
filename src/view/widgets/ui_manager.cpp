#include "../view_facade.h"

#include "../../utils/rect_utils.h"

#include "constants.h"
#include "ui_manager.h"


namespace View::Widgets {

UIManager::UIManager() {

}

void UIManager::draw(Window& window) {
    for (WidgetPtr widgetPtr: _widgets) {
        widgetPtr->draw(window);
    }
}

void UIManager::addWidget(WidgetPtr widget) {
    _widgets.push_back(widget);
}

FontsCache& UIManager::getFontsCache() {
    return _fontsCache;
}

void UIManager::addButton(ButtonPtr button) {
    _widgets.push_back(button);
    _clickables.push_back(button);
}

void UIManager::onMouseButtonDown(unsigned int x, unsigned int y, unsigned int button) {
    for (auto& item: _clickables) {
        const auto& rect = item->getGeometry();
        if (Core::Utils::isInRect(static_cast<int>(x), static_cast<int>(y), rect)) {
            item->onClick();
            return;
        }
    }
}


} // namespace View::Widgets