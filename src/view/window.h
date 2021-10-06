//
// Created by TriD on 07.10.2021.
//

#ifndef EXP_WINDOW_H
#define EXP_WINDOW_H

#include "SDL2/SDL.h"

#include "../settings.h"

class Window {
public:
    explicit Window(const Settings& settings);

    SDL_Renderer* getRenderer() { return _renderer; }

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    Uint32 getScreenPixelFormat();

private:
    int _windowWidth;
    int _windowHeight;

    SDL_Window* _windowImpl;
    SDL_Renderer* _renderer;
};


#endif //EXP_WINDOW_H
