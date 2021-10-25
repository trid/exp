#ifndef LOG_VIEW_H
#define LOG_VIEW_H

#include "widget.h"

#include <deque>
#include <string>

#include "../view_facade.h"

#include "private/log_view_renderer.h"


namespace View::Widgets {

class LogView : public Widget {
public:
    LogView(const UIManager& uiManager, int x, int y);
    void draw(Window& window) override;

    void addMessage(const string& message);
private:
    std::deque<std::string> _messages;

    LogViewRenderer _renderer;
};

} // namespace View::Widgets

#endif // LOG_VIEW_H