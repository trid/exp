#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "widget.h"
#include "../window.h"

using std::string;

namespace View::Widgets {

class UIManager;

class Label : public Widget {
public:
    Label(int x, int y, const UIManager& uiManager, const string& text = "");
    void setText(const string& text);
    void draw(View::Window& window) override;
private:
    string text;
    bool _dirty = true;
    SDL_Texture* renderedText = nullptr;
    SDL_Color textColor;

    const UIManager& _uiManager;
};

} // namespace View::Widgets