#include "label.h"
#include "view.h"
#include "ui_manager.h"


Label::Label(int x, int y, string const &text):
        Widget(x, y), text(text)
{
    textColor.r = 255;
    textColor.g = 255;
    textColor.b = 255;
    textColor.a = 0;
}

void Label::setText(const string &text) {
    this->text = text;
    dirty = true;
}

void Label::draw(SDL_Renderer *renderer) {
    if (dirty) {
        if (renderedText) {
            SDL_DestroyTexture(renderedText);
        }
        SDL_Surface* renderedSurface = TTF_RenderText_Solid(UIManager::getInstance().getFont(), text.c_str(), textColor);
        renderedText = SDL_CreateTextureFromSurface(renderer, renderedSurface);
        SDL_FreeSurface(renderedSurface);
    }
    SDL_Rect rect;
    int w, h;
    SDL_QueryTexture(renderedText, nullptr, nullptr, &w, &h);
    rect.x = getX();
    rect.y = getY();
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(renderer, renderedText, nullptr, &rect);
}
