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

extern View* g_view;
extern SceneObjectManager* g_sceneObjectManager;
World* g_world;
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

    int fontHeight = TTF_FontHeight(_uiManager.getFont());
    int consoleFontHeight = TTF_FontHeight(_uiManager.getConsoleFont());
    woodLabel = new Label(0, 0, _uiManager, "Wood: 0");
    foodLabel = new Label(0, fontHeight, _uiManager, "Food: 0");
    logView = new LogView(*this, _uiManager, 0, windowHeight - consoleFontHeight * 10);
    actorView = new ActorView(windowWidth - 200, 0, _uiManager, *this);

    _uiManager.addWidget(woodLabel);
    _uiManager.addWidget(foodLabel);
    _uiManager.addWidget(logView);
    _uiManager.addWidget(actorView);

    woodUpdater = new WoodUpdaterListener(woodLabel);
    foodUpdater = new FoodUpdaterListener(foodLabel);

    UIMessageManager& uiMessageManager = UIMessageManager::getInstance();
    uiMessageManager.addListener("WOOD_UPDATED_MESSAGE", woodUpdater);
    uiMessageManager.addListener("FOOD_UPDATED_MESSAGE", foodUpdater);

    g_view = this;
}

void View::draw() {
    actorView->updateLabels();
    
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

bool WoodUpdaterListener::listen(UIMessageData const &messageData) {
    std::stringstream ss;
    ss << "Wood: " << g_world->getWood();
    label->setText(ss.str());
    return true;
}

bool FoodUpdaterListener::listen(UIMessageData const &messageData) {
    std::stringstream ss;
    ss << "Food: " << g_world->getFood();
    label->setText(ss.str());
    return true;
}
