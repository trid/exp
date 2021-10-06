//
// Created by TriD on 07.10.2021.
//

#include "window.h"

#include <iostream>

#include "constants.h"

Window::Window(const Settings& settings) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << kSDLInitErrorMessage << std::endl;
        return;
    }
    _windowWidth = settings.getScreenWidth();
    _windowHeight = settings.getScreenHeight();
    _windowImpl = SDL_CreateWindow(kWindowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowWidth,
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

Uint32 Window::getScreenPixelFormat() {
    return SDL_GetWindowPixelFormat(_windowImpl);
}