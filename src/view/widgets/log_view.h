#include "widget.h"
#include "../view.h"

#include <list>
#include <string>

using std::list;
using std::string;

class LogView: public Widget {
public:
    LogView(View& view, const UIManager& uiManager, int x, int y);
    virtual void draw(SDL_Renderer *renderer);

    void addMessage(const string& message);
private:
    list <string> messages;
    bool dirty = true;
    SDL_Color textColor;

    View& _view;
    const UIManager& _uiManager;
};