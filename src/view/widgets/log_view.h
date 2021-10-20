#ifndef LOG_VIEW_H
#define LOG_VIEW_H

#include "widget.h"
#include "../view_facade.h"

#include <list>
#include <string>


namespace View::Widgets {

class LogView : public Widget {
public:
    LogView(View::ViewFacade& view, const UIManager& uiManager, int x, int y);
    virtual void draw(SDL_Renderer* renderer);

    void addMessage(const string& message);
private:
    std::list<std::string> messages;
    bool dirty = true;
    SDL_Color textColor;

    View::ViewFacade& _view;
    const UIManager& _uiManager;
};

} // namespace View::Widgets

#endif // LOG_VIEW_H