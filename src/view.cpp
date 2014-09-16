#include <iostream>

#include "view.h"

using namespace std;

View::View() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init error" << endl;
        return;
    }
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "SDL_CreateWindow error" << endl;
        SDL_Quit();
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        cout << "SDL_CreateRenderer error" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
}

void View::draw() {
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}
