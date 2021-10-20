#include <iostream>
#include <sstream>

#include "view_facade.h"

#include "../ai/actors/agent.h"
#include "../ai/actors/registry.h"
#include "../world.h"
#include "../settings.h"

#include "constants.h"
#include "image.h"

#include "widgets/label.h"
#include "widgets/log_view.h"
#include "widgets/actor_view.h"
#include "widgets/ui_manager.h"

extern Core::AI::Actors::AgentsRegistry* g_actorsRegistry;

namespace View {

ViewFacade::ViewFacade(const Core::Settings& settings, Core::GlobalMessageManager& globalMessageManager, Core::World& world) :
        _window(settings),
        _globalMessageManager(globalMessageManager),
        _sceneObjectManager(*this, world),
        _background(kGrassSpritePath, _window),
        _actor(kActorSpritePath, _window) {
}

void ViewFacade::draw() {
    _window.startDrawing();

    _background.draw(_window);

    //Scene objects before actors
    _sceneObjectManager.draw(_window);

    for (Core::AI::Actors::Agent* actorItem: g_actorsRegistry->getActors()) {
        int x = actorItem->getX();
        int y = actorItem->getY();
        _actor.draw(x, y,_window);
    }

    _uiManager.draw(*this);

    _window.endDrawing();
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