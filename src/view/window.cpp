//
// Created by TriD on 07.10.2021.
//

#include "window.h"

#include <iostream>

#include "../settings.h"

#include "constants.h"

namespace View {

Window::Window(const Core::Settings& settings) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << kSDLInitErrorMessage << std::endl;
        return;
    }
    _windowWidth = settings.getScreenWidth();
    _windowHeight = settings.getScreenHeight();
    _windowImpl = SDL_CreateWindow(settings.getWindowName().c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   _windowWidth,
                                   _windowHeight, SDL_WINDOW_SHOWN);
    if (_windowImpl == nullptr) {
        std::cout << kSDLCreateWindowError << std::endl;
        SDL_Quit();
        return;
    }
    _renderer = SDL_CreateRenderer(_windowImpl, -1,
                                   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
    if (_renderer == nullptr) {
        std::cout << kSDLCreateRendererError << std::endl;
        SDL_DestroyWindow(_windowImpl);
        SDL_Quit();
        return;
    }
}

int Window::getWidth() const { return _windowWidth; }

int Window::getHeight() const { return _windowHeight; }

Uint32 Window::getScreenPixelFormat() const {
    return SDL_GetWindowPixelFormat(_windowImpl);
}

void Window::startDrawing() {
    SDL_RenderClear(_renderer);
}

void Window::endDrawing() {
    SDL_RenderPresent(_renderer);
}

Window::~Window() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_windowImpl);
    SDL_Quit();
}

SDL_Renderer* Window::getRenderer() const { return _renderer; }

} // namespace View