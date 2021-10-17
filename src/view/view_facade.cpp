#include <iostream>
#include <sstream>

#include "view_facade.h"

#include "../ai/actors/agent.h"
#include "../ai/actors/registry.h"
#include "../world.h"
#include "../settings.h"

#include "constants.h"
#include "scene_object_manager.h"

#include "widgets/label.h"
#include "widgets/log_view.h"
#include "widgets/actor_view.h"
#include "widgets/ui_manager.h"


extern View::ViewFacade* g_view;
extern View::SceneObjectManager* g_sceneObjectManager;
extern Core::AI::Actors::AgentsRegistry* g_actorsRegistry;

namespace View {

ViewFacade::ViewFacade(const Core::Settings& settings, Core::GlobalMessageManager& globalMessageManager, Core::World& world) :
        _window(settings),
        _globalMessageManager(globalMessageManager),
        _sceneObjectManager(*this, world) {
    background = IMG_LoadTexture(_window.getRenderer(), kGrassSpritePath);
    actor = IMG_LoadTexture(_window.getRenderer(), kActorSpritePath);

    g_view = this;
}

void ViewFacade::draw() {
    auto renderer = _window.getRenderer();
    SDL_RenderClear(renderer);

    SDL_Rect rect;

    SDL_RenderCopy(renderer, background, nullptr, nullptr);

    //Scene objects before actors
    _sceneObjectManager.draw(renderer);

    rect.w = 100;
    rect.h = 104;
    for (Core::AI::Actors::Agent* actorItem: g_actorsRegistry->getActors()) {
        rect.x = actorItem->getX();
        rect.y = actorItem->getY();
        SDL_RenderCopy(renderer, actor, nullptr, &rect);
    }

    _uiManager.draw(*this);

    SDL_RenderPresent(renderer);
}

Uint32 ViewFacade::getScreenPixelFormat() {
    return _window.getScreenPixelFormat();
}

Widgets::UIManager& ViewFacade::getUiManager() {
    return _uiManager;
}

Core::GlobalMessageManager& ViewFacade::getUIMessageManager() {
    return _globalMessageManager;
}

Window& ViewFacade::getWindow() {
    return _window;
}

} // namespace View