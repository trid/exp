//
// Created by TriD on 29.09.2021.
//

#ifndef EXP_PANEL_H
#define EXP_PANEL_H

#include "actor_view.h"

#include "widget.h"

namespace View {
class ViewFacade;
} // namespace View

namespace Core {
class World;
} // namespace Core

namespace View::Widgets {

class LogView;

class GUIPanel {
public:
    GUIPanel(const Core::World& world, View::ViewFacade& view, UIManager& uiManager);

    void addMessage(const std::string& message);
    void showNextAgent();
    void showPrevAgent();
private:
    const Core::World& _world;

    std::shared_ptr<Label> _foodLabel;
    std::shared_ptr<Label> _woodLabel;
    std::shared_ptr<LogView> _logView;
    std::shared_ptr<ActorView> _actorView;
};

} // namespace View::Widgets

#endif //EXP_PANEL_H
