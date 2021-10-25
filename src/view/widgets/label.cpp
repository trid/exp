#include "label.h"

#include "../fonts_cache.h"
#include "../view_facade.h"

#include "constants.h"
#include "ui_manager.h"

namespace View::Widgets {

Label::Label(int x, int y, UIManager& uiManager, const string& text) :
        Widget(x, y), text(text), _font(uiManager.getFontsCache().getFont(kFontPath, 20)) {
    textColor.r = 255;
    textColor.g = 255;
    textColor.b = 255;
    textColor.a = 0;
}

void Label::setText(const string& text) {
    this->text = text;
    _dirty = true;
}

void Label::draw(Window& window) {
    if (_dirty) {
        _dirty = false;
        if (renderedText) {
            SDL_DestroyTexture(renderedText);
        }
        SDL_Surface* renderedSurface = TTF_RenderText_Solid(_font.getImpl(), text.c_str(), textColor);
        renderedText = SDL_CreateTextureFromSurface(window.getRenderer(), renderedSurface);
        SDL_FreeSurface(renderedSurface);
    }
    SDL_Rect rect;
    int w, h;
    SDL_QueryTexture(renderedText, nullptr, nullptr, &w, &h);
    rect.x = getX();
    rect.y = getY();
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(window.getRenderer(), renderedText, nullptr, &rect);
}

} // namespace View::Widgets