//
// Created by TriD on 29.09.2021.
//

#ifndef EXP_PANEL_H
#define EXP_PANEL_H

#include "actor_view.h"
#include "log_view.h"

#include "widget.h"

class View;

namespace Core {
class World;
} // namespace Core

class GUIPanel {
public:
    GUIPanel(const Core::World& world, View& view);

    void addMessage(const string &message);
    void showNextAgent();
    void showPrevAgent();
private:
    const Core::World& _world;

    std::shared_ptr<Label> _foodLabel;
    std::shared_ptr<Label> _woodLabel;
    std::shared_ptr<LogView> _logView;
    std::shared_ptr<ActorView> _actorView;
};

#endif //EXP_PANEL_H
