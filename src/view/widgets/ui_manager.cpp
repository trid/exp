#include "../view_facade.h"

#include "constants.h"

namespace View::Widgets {

UIManager::UIManager() {
    TTF_Init();
    font = TTF_OpenFont(kFontPath, 20);
    logFont = TTF_OpenFont(kFontPath, 14);
}

void UIManager::draw(ViewFacade& view) {
    for (WidgetPtr widgetPtr: widgets) {
        widgetPtr->draw(view.getWindow().getRenderer());
    }
}

void UIManager::addWidget(WidgetPtr widget) {
    widgets.push_back(WidgetPtr(widget));
}

} // namespace View::Widgets