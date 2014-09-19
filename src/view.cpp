#include <iostream>

#include "view.h"

#include "actor.h"
#include "registry.h"

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

    background = IMG_LoadTexture(renderer, "res/img/grass.jpg");
    well = IMG_LoadTexture(renderer, "res/img/well.png");
    forest = IMG_LoadTexture(renderer, "res/img/trees.png");
    home = IMG_LoadTexture(renderer, "res/img/home.png");
    actor = IMG_LoadTexture(renderer, "res/img/actor.png");
}

void View::draw() {
    SDL_RenderClear(renderer);

    SDL_Rect rect;

    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    rect.x = 400;
    rect.y = 300;
    rect.w = 320;
    rect.h = 240;
    SDL_RenderCopy(renderer, home, nullptr, &rect);
    rect.x = 500;
    rect.y = 0;
    rect.w = 100;
    rect.h = 128;
    SDL_RenderCopy(renderer, forest, nullptr, &rect);
    rect.x = 200;
    rect.y = 200;
    rect.w = 66;
    rect.h = 72;
    SDL_RenderCopy(renderer, well, nullptr, &rect);

    rect.w = 100;
    rect.h = 104;
    for (Actor* actorItem: ActorsRegistry::getRegistry().getActors()) {
        switch (actorItem->getPosition()) {
            case POSITION_NONE:
                break;
            case POSITION_HOME:
                rect.x = 400;
                rect.y = 300;
                break;
            case POSITION_FOREST:
                rect.x = 500;
                rect.y = 0;
                break;
            case POSITION_WATER:
                rect.x = 200;
                rect.y = 200;
                break;
        }
        SDL_RenderCopy(renderer, actor, nullptr, &rect);
    }

    SDL_RenderPresent(renderer);
}
