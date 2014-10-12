#include "widget.h"

#include <list>
#include <string>

using std::list;
using std::string;

class LogView: public Widget {
private:
    list <string> messages;
    bool dirty = true;
    SDL_Color textColor;
public:

    LogView(int x, int y);
    virtual void draw(SDL_Renderer *renderer);

    void addMessage(const string& message);
};