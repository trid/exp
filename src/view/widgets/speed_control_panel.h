//
// Created by TriD on 13.01.2022.
//

#ifndef EXP_SPEED_CONTROL_PANEL_H
#define EXP_SPEED_CONTROL_PANEL_H

#include <memory>

namespace Core {
class Timer;
} // namespace Core

namespace View {
class ViewFacade;
}

namespace View::Widgets {

class Label;
class UIManager;

class SpeedControlPanel {
public:
    explicit SpeedControlPanel(View::ViewFacade& view, Core::Timer& timer);

private:
    std::shared_ptr<Label> _speedLabel;
};

} // namespace View::Widgets

#endif //EXP_SPEED_CONTROL_PANEL_H
