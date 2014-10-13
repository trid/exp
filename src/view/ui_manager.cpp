#include "ui_manager.h"
#include "view.h"

UIManager::UIManager() {
    TTF_Init();
    font = TTF_OpenFont("res/fonts/FreeSans.ttf", 20);
    logFont = TTF_OpenFont("res/fonts/FreeSans.ttf", 14);
}

void UIManager::draw() {
    View& view = View::getView();
    for (WidgetPtr widgetPtr: widgets){
        widgetPtr->draw(view.getRenderer());
    }
}

void UIManager::addWidget(Widget *widget) {
    widgets.push_back(WidgetPtr(widget));
}
