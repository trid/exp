#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../window.h"
#include "../font.h"

#include "widget.h"

#include "private/label_renderer.h"

using std::string;

namespace View::Widgets {

class UIManager;

class Label : public Widget {
public:
    Label(int x, int y, UIManager& uiManager, string&& text = "");
    void setText(string&& text);
    void draw(View::Window& window) override;
private:
    LabelRenderer _labelRenderer;
};

} // namespace View::Widgets