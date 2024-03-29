//
// Created by TriD on 20.10.2021.
//

#include "image.h"

#include <SDL2/SDL_image.h>

#include "window.h"

namespace View {

Image::Image(const std::string& filePath, const Window& window) {
    _texture = IMG_LoadTexture(window.getRenderer(), filePath.c_str());
}

Image::Image(Image&& other)  noexcept {
    _texture = other._texture;
    other._texture = nullptr;
}

Image::~Image() {
    if (_texture) {
        SDL_DestroyTexture(_texture);
    }
}

Image& Image::operator=(Image&& other) noexcept {
    _texture = other._texture;
    other._texture = nullptr;
    return *this;
}

void Image::draw(int x, int y, int w, int h, Window& window) {
    SDL_Rect dstRect{x, y, w, h};
    SDL_RenderCopy(window.getRenderer(), _texture, nullptr, &dstRect);
}

void Image::draw(int x, int y, const Window& window) {
    SDL_Rect dstRect{x, y, 0, 0};
    SDL_QueryTexture(_texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
    SDL_RenderCopy(window.getRenderer(), _texture, nullptr, &dstRect);
}

void Image::draw(Window& window) {
    SDL_RenderCopy(window.getRenderer(), _texture, nullptr, nullptr);
}

}