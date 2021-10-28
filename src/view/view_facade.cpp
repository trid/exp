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
#include "widgets/actor_info_view.h"
#include "widgets/ui_manager.h"

extern Core::AI::Actors::AgentsRegistry* g_actorsRegistry;

namespace View {

ViewFacade::ViewFacade(const Core::Settings& settings, Core::GlobalMessageManager& globalMessageManager, Core::World& world) :
        _window(settings),
        _background(kGrassSpritePath, _window),
        _actor(kActorSpritePath, _window),
        _globalMessageManager(globalMessageManager),
        _sceneObjectManager(*this, world),
        _guiPanel(world, *this, _uiManager)
         {
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

    _uiManager.draw(_window);

    _window.endDrawing();
}

Uint32 ViewFacade::getScreenPixelFormat() const {
    return _window.getScreenPixelFormat();
}

Core::GlobalMessageManager& ViewFacade::getUIMessageManager() {
    return _globalMessageManager;
}

Window& ViewFacade::getWindow() {
    return _window;
}

View::Widgets::GUIPanel& ViewFacade::getGUIPanel() {
    return _guiPanel;
}

} // namespace View