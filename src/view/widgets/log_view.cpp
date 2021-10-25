#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include "log_view.h"
#include "../view_facade.h"
#include "ui_manager.h"

namespace View::Widgets {

void LogView::draw(Window& window) {
    _renderer.draw(getX(), getY(), _messages, window);
}

void LogView::addMessage(const string& message) {
    _messages.push_back(message);
    while (_messages.size() > 10) {
        _messages.pop_front();
    }

    _renderer.enforceUpdate();
}

LogView::LogView(const UIManager& uiManager, int x, int y) :
        Widget(x, y),
        _renderer(uiManager) {
}

} // namespace View::Widgets