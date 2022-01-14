#include <iostream>

#include "view_facade.h"

#include "../ai/agents/agent.h"
#include "../ai/agents/agent_registry.h"
#include "../core/world.h"

#include "constants.h"

#include "widgets/label.h"
#include "widgets/log_view.h"


namespace View {

ViewFacade::ViewFacade(const Core::Settings& settings, Core::GlobalMessageManager& globalMessageManager,
                       Core::World& world,
                       Core::Timer& timer) :
        _window(settings),
        _background(kGrassSpritePath, _window),
        _globalMessageManager(globalMessageManager),
        _sceneObjectManager(*this, world),
        _guiPanel(world, *this, _uiManager),
        _speedControlPanel(*this, timer),
        _agentsRegistry(world.getAgentsRegistry())
         {
     _actors.emplace(std::piecewise_construct, std::forward_as_tuple(kActorGreenType), std::forward_as_tuple(kActorGreenSpritePath, _window));
     _actors.emplace(std::piecewise_construct, std::forward_as_tuple(kActorBlueType), std::forward_as_tuple(kActorBlueSpritePath, _window));
}

void ViewFacade::draw() {
    _window.startDrawing();

    _background.draw(_window);

    //Scene objects before agents
    _sceneObjectManager.draw(_window);

    for (const auto& actorItem: _agentsRegistry.getActors()) {
        int x = actorItem.getX();
        int y = actorItem.getY();
        _actors.at(actorItem.getType()).draw(x, y,_window);
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

View::Widgets::UIManager& ViewFacade::getUIManager() {
    return _uiManager;
}

} // namespace View