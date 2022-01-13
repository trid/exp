#include "log_view.h"

#include "ui_manager.h"
#include "constants.h"


namespace View::Widgets {

LogView::LogView(int x, int y, UIManager& uiManager) :
        Widget(x, y),
        _renderer(uiManager.getFontsCache().getFont(kFontPath, 14)) {
}

void LogView::draw(Window& window) {
    _renderer.draw(getX(), getY(), _messages, window);
}

void LogView::addMessage(const std::string& message) {
    _messages.push_back(message);
    while (_messages.size() > kMaxLogMessages) {
        _messages.pop_front();
    }

    _renderer.enforceUpdate();
}

} // namespace View::Widgets