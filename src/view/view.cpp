#include <iostream>
#include <sstream>

#include "view.h"

#include "../actor.h"
#include "../registry.h"
#include "../world.h"

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
    actor = IMG_LoadTexture(renderer, "res/img/actor.png");

    TTF_Init();
    Label::font = TTF_OpenFont("res/fonts/FreeSans.ttf", 20);

    woodLabel = new Label(0, 0, "Wood: 0");
    foodLabel = new Label(0, 30, "Food: 0");
}

void View::draw() {
    updateLabels();
    
    SDL_RenderClear(renderer);

    SDL_Rect rect;

    SDL_RenderCopy(renderer, background, nullptr, nullptr);

    for (MapObjectPtr ptr: mapObjects) {
        ptr->draw(renderer);
    }

    rect.w = 100;
    rect.h = 104;
    for (Actor* actorItem: ActorsRegistry::getRegistry().getActors()) {
        if (actorItem->getPosition() == "home") {
            rect.x = 400;
            rect.y = 300;
        }
        if (actorItem->getPosition() == "forest") {
            rect.x = 500;
            rect.y = 0;
        }
        if (actorItem->getPosition() == "water") {
            rect.x = 200;
            rect.y = 200;
        }
        SDL_RenderCopy(renderer, actor, nullptr, &rect);
    }

    foodLabel->draw(renderer);
    woodLabel->draw(renderer);

    SDL_RenderPresent(renderer);
}

void View::updateLabels() {
    std::stringstream ss;
    World &world = World::getWorld();
    ss << "Wood: " << world.getWood();
    woodLabel->setText(ss.str());
    ss.str("");
    ss << "Food: " << world.getFood();
    foodLabel->setText(ss.str());
}

void View::registerMapObject(int x, int y, const string &path) {
    MapObjectPtr ptr(new MapObject(x, y, path));
    mapObjects.push_back(ptr);
}
