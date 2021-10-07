//
// Created by TriD on 29.09.2021.
//

#include "gui_panel.h"

#include <sstream>

#include "../../constants.h"
#include "../../world.h"

#include "constants.h"
#include "label.h"

extern View::Widgets::GUIPanel* g_panel;

namespace View::Widgets {

class WoodUpdaterListener : public IUIMessageListener {
private:
    Label& _label;
    const Core::World& _world;
public:
    WoodUpdaterListener(Label& label, const Core::World& world) :
            _label(label),
            _world(world) {}

    virtual bool listen(UIMessageData const& messageData) {
        std::stringstream ss;
        ss << kWoodLabelPrefix << _world.getWood();
        _label.setText(ss.str());
        return true;
    }
};

class FoodUpdaterListener : public IUIMessageListener {
private:
    Label& _label;
    const Core::World& _world;
public:
    FoodUpdaterListener(Label& label, const Core::World& world) :
            _label(label),
            _world(world) {}

    virtual bool listen(UIMessageData const& messageData) {
        std::stringstream ss;
        ss << kFoodLabelPrefix << _world.getFood();
        _label.setText(ss.str());
        return true;
    }
};

GUIPanel::GUIPanel(const Core::World& world, View::ViewFacade& view) :
        _world(world) {
    g_panel = this;

    auto& uiManager = view.getUiManager();

    int fontHeight = TTF_FontHeight(uiManager.getFont());
    int consoleFontHeight = TTF_FontHeight(uiManager.getConsoleFont());

    _woodLabel = std::make_shared<Label>(0, 0, uiManager, std::string(kWoodLabelPrefix) + "0");
    _foodLabel = std::make_shared<Label>(0, fontHeight, uiManager, std::string(kFoodLabelPrefix) + "0");
    _logView = std::make_shared<LogView>(view, uiManager, 0, view.getWindow().getHeight() - consoleFontHeight * 10);
    _actorView = std::make_shared<ActorView>(view.getWindow().getWidth() - kActorDataViewWidth, 0, uiManager, view);

    uiManager.addWidget(_woodLabel);
    uiManager.addWidget(_foodLabel);
    uiManager.addWidget(_logView);
    uiManager.addWidget(_actorView);

    auto woodUpdater = std::make_unique<WoodUpdaterListener>(*_woodLabel, world);
    auto foodUpdater = std::make_unique<FoodUpdaterListener>(*_foodLabel, world);

    UIMessageManager& uiMessageManager = view.getUIMessageManager();
    uiMessageManager.addListener(Core::kWoodUpdatedMessage, std::move(woodUpdater));
    uiMessageManager.addListener(Core::kFoodUpdatedMessage, std::move(foodUpdater));
}

void GUIPanel::addMessage(const string& message) {
    _logView->addMessage(message);
}

void GUIPanel::showNextAgent() {
    _actorView->nextActor();
}

void GUIPanel::showPrevAgent() {
    _actorView->prevActor();
}

} // namespace