#include <iostream>
#include <sstream>

#include "view.h"

#include "../ai/actor.h"
#include "../ai/registry.h"
#include "../world.h"
#include "../settings.h"

#include "constants.h"
#include "scene_object_manager.h"

#include "widgets/label.h"
#include "widgets/log_view.h"
#include "widgets/actor_view.h"
#include "widgets/ui_manager.h"

using namespace std;

extern View* g_view;
extern SceneObjectManager* g_sceneObjectManager;
extern ActorsRegistry* g_actorsRegistry;

View::View(const Core::Settings& settings):
    _window(settings)
{
    background = IMG_LoadTexture(_window.getRenderer(), kGrassSpritePath);
    actor = IMG_LoadTexture(_window.getRenderer(), kActorSpritePath);

    g_view = this;
}

void View::draw() {
    auto renderer = _window.getRenderer();
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
    return _window.getScreenPixelFormat();
}

UIManager& View::getUiManager() {
    return _uiManager;
}

UIMessageManager& View::getUIMessageManager() {
    return _uiMessageManager;
}

Window& View::getWindow() {
    return _window;
}

