//
// Created by TriD on 13.01.2022.
//

#include "speed_control_panel.h"

#include "../../timer.h"

#include "../view_facade.h"

#include "button.h"
#include "constants.h"
#include "label.h"
#include "ui_manager.h"

namespace View::Widgets {

class NormalSpeedButton : public Button {
public:
    explicit NormalSpeedButton(Core::Timer& timer, std::shared_ptr<Label> speedLabel, const IntRect& geometry, Image&& image) :
            Button(geometry, std::move(image)),
            _timer(timer),
            _speedLabel(speedLabel) {}

    void onClick() override {
        _timer.setMultiplier(1);
        _speedLabel->setText("Speed: 1");
    }

private:
    Core::Timer& _timer;
    std::shared_ptr<Label> _speedLabel;
};

class DoubleSpeedButton : public Button {
public:
    explicit DoubleSpeedButton(Core::Timer& timer, std::shared_ptr<Label> speedLabel, const IntRect& geometry, Image&& image) :
            Button(geometry, std::move(image)),
            _speedLabel(speedLabel),
            _timer(timer) {}

    void onClick() override {
        _timer.setMultiplier(4);
        _speedLabel->setText("Speed: 4");
    }

private:
    Core::Timer& _timer;
    std::shared_ptr<Label> _speedLabel;
};

SpeedControlPanel::SpeedControlPanel(ViewFacade& view, Core::Timer& timer) {
    auto& uiManager = view.getUIManager();
    auto& window = view.getWindow();

    auto consoleFontHeight = uiManager.getFontsCache().getFont(kFontPath, 14).getSize();
    auto logMessagesPosY = window.getHeight() - consoleFontHeight * kMaxLogMessages;

    auto speedButtonsPosX = window.getWidth() - kSpeedPanelRightOffset;
    auto speedButtonsPosY = static_cast<int>(logMessagesPosY - kSpeedButtonHeight);
    auto speedLabelPosY = speedButtonsPosY - consoleFontHeight - 5;

    auto speedLabel = std::make_shared<Label>(speedButtonsPosX, speedLabelPosY, uiManager, "Speed: 1");
    uiManager.addWidget(speedLabel);

    auto buttonSpeedNormal = std::make_shared<NormalSpeedButton>(timer, speedLabel,
                                                                 IntRect{speedButtonsPosX, speedButtonsPosY,
                                                                         kSpeedButtonWidth,
                                                                         kSpeedButtonHeight},
                                                                 Image(kButtonSpeed1, window));
    auto buttonSpeedDouble = std::make_shared<DoubleSpeedButton>(timer, speedLabel,
                                                                 IntRect{speedButtonsPosX + kSpeedButtonWidth + 5,
                                                                         speedButtonsPosY,
                                                                         kSpeedButtonWidth,
                                                                         kSpeedButtonHeight},
                                                                 Image(kButtonSpeed2, window));
    uiManager.addButton(buttonSpeedNormal);
    uiManager.addButton(buttonSpeedDouble);
}

} // namespace View::Widgets