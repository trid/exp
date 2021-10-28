//
// Created by TriD on 28.10.2021.
//

#include "label_renderer.h"

#include "../../window.h"

namespace View::Widgets {

LabelRenderer::LabelRenderer(int x, int y, std::string&& text, Font&& font) :
    _text(text), _font(font), _x(x), _y(y)
{

}

void LabelRenderer::setText(std::string&& text) {
    _text = text;
    _dirty = true;
}

void LabelRenderer::draw(Window& window) {
    if (_dirty) {
        _dirty = false;
        if (_renderedText) {
            SDL_DestroyTexture(_renderedText);
        }
        SDL_Surface* renderedSurface = TTF_RenderText_Solid(_font.getImpl(), _text.c_str(), _textColor);
        _renderedText = SDL_CreateTextureFromSurface(window.getRenderer(), renderedSurface);
        SDL_FreeSurface(renderedSurface);
    }
    SDL_Rect rect;
    int w, h;
    SDL_QueryTexture(_renderedText, nullptr, nullptr, &w, &h);
    rect.x = _x;
    rect.y = _y;
    rect.w = w;
    rect.h = h;
    SDL_RenderCopy(window.getRenderer(), _renderedText, nullptr, &rect);
}

}