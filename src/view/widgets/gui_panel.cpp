//
// Created by TriD on 29.09.2021.
//

#include "gui_panel.h"

#include <sstream>

#include "../../world.h"

#include "label.h"

extern GUIPanel* g_panel;

class WoodUpdaterListener: public IUIMessageListener {
private:
    Label& _label;
    const World& _world;
public:
    WoodUpdaterListener(Label& label, const World& world):
        _label(label),
        _world(world) {}

    virtual bool listen(UIMessageData const &messageData) {
        std::stringstream ss;
        ss << "Wood: " << _world.getWood();
        _label.setText(ss.str());
        return true;
    }
};

class FoodUpdaterListener: public IUIMessageListener {
private:
    Label& _label;
    const World& _world;
public:
    FoodUpdaterListener(Label& label, const World& world):
        _label(label),
        _world(world) {}

    virtual bool listen(UIMessageData const &messageData) {
        std::stringstream ss;
        ss << "Food: " << _world.getFood();
        _label.setText(ss.str());
        return true;
    }
};

GUIPanel::GUIPanel(const World& world, View& view):
    _world(world)
{
    g_panel = this;

    auto& uiManager = view.getUiManager();

    int fontHeight = TTF_FontHeight(uiManager.getFont());
    int consoleFontHeight = TTF_FontHeight(uiManager.getConsoleFont());

    _woodLabel = std::make_shared<Label>(0, 0, uiManager, "Wood: 0");
    _foodLabel = std::make_shared<Label>(0, fontHeight, uiManager, "Food: 0");
    _logView = std::make_shared<LogView>(view, uiManager, 0, view.getWindowHeight() - consoleFontHeight * 10);
    _actorView = std::make_shared<ActorView>(view.getWindowWidth() - 200, 0, uiManager, view);

    uiManager.addWidget(_woodLabel);
    uiManager.addWidget(_foodLabel);
    uiManager.addWidget(_logView);
    uiManager.addWidget(_actorView);

    auto woodUpdater = std::make_unique<WoodUpdaterListener>(*_woodLabel, world);
    auto foodUpdater = std::make_unique<FoodUpdaterListener>(*_foodLabel, world);

    UIMessageManager& uiMessageManager = view.getUIMessageManager();
    uiMessageManager.addListener("WOOD_UPDATED_MESSAGE", std::move(woodUpdater));
    uiMessageManager.addListener("FOOD_UPDATED_MESSAGE", std::move(foodUpdater));
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