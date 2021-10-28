#include "label.h"

#include "../fonts_cache.h"
#include "../view_facade.h"

#include "constants.h"
#include "ui_manager.h"

namespace View::Widgets {

Label::Label(int x, int y, UIManager& uiManager, string&& text) :
        Widget(x, y), _labelRenderer(x, y, std::move(text), uiManager.getFontsCache().getFont(kFontPath, 20)) {

}

void Label::setText(string&& text) {
    _labelRenderer.setText(std::move(text));
}

void Label::draw(Window& window) {
    _labelRenderer.draw(window);
}

} // namespace View::Widgets