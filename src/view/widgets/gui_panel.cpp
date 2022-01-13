//
// Created by TriD on 29.09.2021.
//

#include "gui_panel.h"

#include <sstream>

#include "../../constants.h"
#include "../../message_data.h"
#include "../../world.h"

#include "../view_facade.h"

#include "constants.h"
#include "label.h"
#include "log_view.h"


namespace View::Widgets {

class WoodUpdaterListener : public Core::MessageListener {
public:
    WoodUpdaterListener(Label& label, const Core::World& world) :
            _label(label),
            _world(world) {}

    bool listen(Core::MessageData const& messageData) override {
        std::stringstream ss;
        ss << kWoodLabelPrefix << _world.getWood();
        _label.setText(ss.str());
        return true;
    }

private:
    Label& _label;
    const Core::World& _world;
};

class FoodUpdaterListener : public Core::MessageListener {
public:
    FoodUpdaterListener(Label& label, const Core::World& world) :
            _label(label),
            _world(world) {}

    bool listen(Core::MessageData const& messageData) override {
        std::stringstream ss;
        ss << kFoodLabelPrefix << _world.getFood();
        _label.setText(ss.str());
        return true;
    }

private:
    Label& _label;
    const Core::World& _world;
};

class AgentPhraseListener : public Core::MessageListener {
public:
    explicit AgentPhraseListener(LogView& logView) :
            _logView(logView) {}

    bool listen(Core::MessageData const& messageData) override {
        _logView.addMessage(std::get<std::string>(*messageData.getParameter(Core::kAgentPhraseMessageKey)));
        return true;
    }

private:
    LogView& _logView;
};

GUIPanel::GUIPanel(const Core::World& world, View::ViewFacade& view, UIManager& uiManager) :
        _world(world) {
    int fontHeight = uiManager.getFontsCache().getFont(kFontPath, 20).getSize();
    int consoleFontHeight = uiManager.getFontsCache().getFont(kFontPath, 14).getSize();

    _woodLabel = std::make_shared<Label>(0, 0, uiManager, std::string(kWoodLabelPrefix) + "0");
    _foodLabel = std::make_shared<Label>(0, fontHeight, uiManager, std::string(kFoodLabelPrefix) + "0");
    _logView = std::make_shared<LogView>(0, view.getWindow().getHeight() - consoleFontHeight * kMaxLogMessages,
                                         uiManager);
    _actorView = std::make_shared<ActorInfoView>(view.getWindow().getWidth() - kActorDataViewWidth, 0, world, uiManager,
                                                 view);

    uiManager.addWidget(_woodLabel);
    uiManager.addWidget(_foodLabel);
    uiManager.addWidget(_logView);
    uiManager.addWidget(_actorView);

    auto woodUpdater = std::make_unique<WoodUpdaterListener>(*_woodLabel, world);
    auto foodUpdater = std::make_unique<FoodUpdaterListener>(*_foodLabel, world);
    auto agentPhraseListener = std::make_unique<AgentPhraseListener>(*_logView);

    auto& uiMessageManager = view.getUIMessageManager();
    uiMessageManager.addListener(Core::kWoodUpdatedMessage, std::move(woodUpdater));
    uiMessageManager.addListener(Core::kFoodUpdatedMessage, std::move(foodUpdater));
    uiMessageManager.addListener(Core::kAgentPhraseMessage, std::move(agentPhraseListener));
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