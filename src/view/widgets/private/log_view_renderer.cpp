//
// Created by TriD on 25.10.2021.
//

#include "log_view_renderer.h"

#include "../../window.h"


namespace View::Widgets {

LogViewRenderer::LogViewRenderer(Font font) : _font(font) {}

void LogViewRenderer::draw(int x, int y, const std::deque<std::string>& messages, Window& window) {
    auto* renderer = window.getRenderer();
    if (_dirty) {
        _dirty = false;
        updateSurface(messages, window, renderer);
    }
    drawMessages(x, y, renderer);
}

void LogViewRenderer::drawMessages(int x, int y, SDL_Renderer* renderer) const {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(_surface, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, _surface, nullptr, &rect);
}

void
LogViewRenderer::updateSurface(const std::deque<std::string>& messages, const Window& window, SDL_Renderer* renderer) {
    if (_surface) {
        SDL_DestroyTexture(_surface);
    }
    int height = _font.getSize();
    int surfaceHeight = height * 10;
    _surface = SDL_CreateTexture(renderer, window.getScreenPixelFormat(), SDL_TEXTUREACCESS_TARGET,
                                 window.getWidth(), surfaceHeight);
    SDL_SetTextureBlendMode(_surface, SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(renderer, _surface);

    SDL_SetRenderDrawColor(renderer, 10, 10, 50, 100);
    SDL_RenderClear(renderer);

    drawMessagesToSurface(messages, renderer, height);

    SDL_SetRenderTarget(renderer, nullptr);
}

void LogViewRenderer::drawMessagesToSurface(const std::deque<std::string>& messages, SDL_Renderer* renderer,
                                            int height) const {
    int currentHeight = 0;
    for (const auto& str: messages) {
        SDL_Surface* renderedSurface = TTF_RenderText_Solid(_font.getImpl(), str.c_str(), _textColor);
        SDL_Texture* renderedText = SDL_CreateTextureFromSurface(renderer, renderedSurface);
        SDL_FreeSurface(renderedSurface);
        SDL_Rect rect;
        rect.x = 0;
        rect.y = currentHeight;
        SDL_QueryTexture(renderedText, nullptr, nullptr, &rect.w, &rect.h);
        SDL_RenderCopy(renderer, renderedText, nullptr, &rect);
        SDL_DestroyTexture(renderedText);
        currentHeight += height;
    }
}

void LogViewRenderer::enforceUpdate() {
    _dirty = true;
}

}