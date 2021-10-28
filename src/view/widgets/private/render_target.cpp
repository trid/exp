//
// Created by TriD on 27.10.2021.
//

#include "render_target.h"

#include "../../window.h"

namespace View::Widgets {

RenderTarget::RenderTarget(int x, int y, int width, int height, Window& window): _x(x), _y(y) {
    _texture = SDL_CreateTexture(window.getRenderer(), window.getScreenPixelFormat(), SDL_TEXTUREACCESS_TARGET, width,
                                 height);
    SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
}

RenderTarget::~RenderTarget() {
    SDL_DestroyTexture(_texture);
}

void RenderTarget::startDrawing(Window& window) {
    auto* renderer = window.getRenderer();
    SDL_SetRenderTarget(renderer, _texture);
    SDL_SetRenderDrawColor(renderer, _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
    SDL_RenderClear(renderer);
}

void RenderTarget::endDrawing(Window& window) {
    auto* renderer = window.getRenderer();
    SDL_SetRenderTarget(renderer, nullptr);

    SDL_Rect rect;
    rect.x = _x;
    rect.y = _y;
    SDL_QueryTexture(_texture, nullptr, nullptr, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, _texture, nullptr, &rect);
}

void RenderTarget::setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    _backgroundColor = {r, g, b, a};
}

} // namespace View::Widgets