#include "widget.h"
#include "../view_facade.h"

#include <list>
#include <string>

using std::list;
using std::string;

namespace View::Widgets {

class LogView : public Widget {
public:
    LogView(View::ViewFacade& view, const UIManager& uiManager, int x, int y);
    virtual void draw(SDL_Renderer* renderer);

    void addMessage(const string& message);
private:
    list<string> messages;
    bool dirty = true;
    SDL_Color textColor;

    View::ViewFacade& _view;
    const UIManager& _uiManager;
};

} // namespace View::Widgets