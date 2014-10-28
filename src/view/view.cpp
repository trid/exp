#include <iostream>
#include <sstream>

#include "view.h"

#include "../ai/actor.h"
#include "../ai/registry.h"
#include "../world.h"
#include "../settings.h"

#include "label.h"
#include "log_view.h"
#include "actor_view.h"
#include "ui_manager.h"
#include "scene_object_manager.h"

using namespace std;

View::View() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init error" << endl;
        return;
    }
    windowWidth = Settings::getSettings().getIntParameter("screen_width");
    windowHeight = Settings::getSettings().getIntParameter("screen_height");
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

    int fontHeight = TTF_FontHeight(UIManager::getInstance().getFont());
    int consoleFontHeight = TTF_FontHeight(UIManager::getInstance().getConsoleFont());
    woodLabel = new Label(0, 0, "Wood: 0");
    foodLabel = new Label(0, fontHeight, "Food: 0");
    logView = new LogView(0, windowHeight - consoleFontHeight * 10);
    actorView = new ActorView(windowWidth - 200, 0);
    UIManager &uiManager = UIManager::getInstance();
    uiManager.addWidget(woodLabel);
    uiManager.addWidget(foodLabel);
    uiManager.addWidget(logView);
    uiManager.addWidget(actorView);
}

void View::draw() {
    updateLabels();
    
    SDL_RenderClear(renderer);

    SDL_Rect rect;

    SDL_RenderCopy(renderer, background, nullptr, nullptr);

    //Scene objects before actors
    SceneObjectManager::getInstance().draw(renderer);

    for (MapObjectPtr ptr: mapObjects) {
        ptr->draw(renderer);
    }

    rect.w = 100;
    rect.h = 104;
    for (Actor* actorItem: ActorsRegistry::getRegistry().getActors()) {
        /*if (actorItem->getPosition() == "home") {
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
        }*/
        rect.x = actorItem->getX();
        rect.y = actorItem->getY();
        SDL_RenderCopy(renderer, actor, nullptr, &rect);
    }

    UIManager::getInstance().draw();

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
    actorView->updateLabels();
}

void View::addMessage(const string &message) {
    logView->addMessage(message);
}

Uint32 View::getScreenPixelFormat() {
    return SDL_GetWindowPixelFormat(window);
}

void View::showNextAgent() {
    actorView->nextActor();
}

void View::showPrevAgent() {
    actorView->prevActor();
}
