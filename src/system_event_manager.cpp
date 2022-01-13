#include <SDL2/SDL_events.h>
#include "system_event_manager.h"
#include "application.h"
#include "view/view_facade.h"

namespace Core {

void SystemEventManager::process() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            _application.finish();
        }
        if (e.type == SDL_KEYUP) {
            if (e.key.keysym.sym == SDLK_LEFT) {
                _guiPanel.showPrevAgent();
            }
            if (e.key.keysym.sym == SDLK_RIGHT) {
                _guiPanel.showNextAgent();
            }
        }
        if (e.type == SDL_MOUSEBUTTONDOWN) {
            _uiManager.onMouseButtonDown(e.button.x, e.button.y, e.button.button);
        }
    }
}

SystemEventManager::SystemEventManager(Application& application, View::Widgets::UIManager& uiManager,
                                       View::Widgets::GUIPanel& guiPanel) :
        _application(application),
        _uiManager(uiManager),
        _guiPanel(guiPanel) {}

} // namespace Core