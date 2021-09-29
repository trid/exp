#include <iostream>
#include <sstream>

#include "view.h"

#include "../ai/actor.h"
#include "../ai/registry.h"
#include "../world.h"
#include "../settings.h"

#include "widgets/label.h"
#include "widgets/log_view.h"
#include "widgets/actor_view.h"
#include "widgets/ui_manager.h"
#include "scene_object_manager.h"

using namespace std;

extern View* g_view;
extern SceneObjectManager* g_sceneObjectManager;
extern ActorsRegistry* g_actorsRegistry;

View::View(const Settings& settings) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init error" << endl;
        return;
    }
    windowWidth = settings.getIntParameter("screen_width");
    windowHeight = settings.getIntParameter("screen_height");
    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "SDL_CreateWindow error" << endl;
        SDL_Quit();
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
    if (renderer == nullptr) {
        cout << "SDL_CreateRenderer error" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    background = IMG_LoadTexture(renderer, "res/img/grass.jpg");
    actor = IMG_LoadTexture(renderer, "res/img/actor.png");

    g_view = this;
}

void View::draw() {
    SDL_RenderClear(renderer);

    SDL_Rect rect;

    SDL_RenderCopy(renderer, background, nullptr, nullptr);

    //Scene objects before actors
    g_sceneObjectManager->draw(renderer);

    for (MapObjectPtr ptr: mapObjects) {
        ptr->draw(renderer);
    }

    rect.w = 100;
    rect.h = 104;
    for (Actor* actorItem: g_actorsRegistry->getActors()) {
        rect.x = actorItem->getX();
        rect.y = actorItem->getY();
        SDL_RenderCopy(renderer, actor, nullptr, &rect);
    }

    _uiManager.draw(*this);

    SDL_RenderPresent(renderer);
}

Uint32 View::getScreenPixelFormat() {
    return SDL_GetWindowPixelFormat(window);
}

UIManager& View::getUiManager() {
    return _uiManager;
}

UIMessageManager& View::getUIMessageManager() {
    return _uiMessageManager;
}

