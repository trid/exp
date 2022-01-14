#include <sstream>
#include <SDL2/SDL_ttf.h>

#include "../../ai/actors/agent.h"
#include "../../ai/actors/agent_registry.h"

#include "../../core/constants.h"
#include "../../core/world.h"

#include "../view_facade.h"

#include "constants.h"
#include "label.h"


namespace View::Widgets {

ActorInfoView::ActorInfoView(int x, int y, const Core::World& world, UIManager& uiManager, ViewFacade& view) :
        Widget(x, y),
        _font(uiManager.getFontsCache().getFont(kFontPath, 20)),
        _renderTarget(x, y, kActorDataViewWidth, _font.getSize() * 4, view.getWindow()),
        _world(world)
{
    _renderTarget.setBackgroundColor(10, 10, 50, 100);

    int fontHeight = _font.getSize();
    _nameLabel = std::make_unique<Label>(0, 0, uiManager, kNameLabelPrefix);
    _foodLabel = std::make_unique<Label>(0, fontHeight, uiManager, kFoodLabelPrefix);
    _waterLabel = std::make_unique<Label>(0, fontHeight * 2, uiManager, kWaterLabelPrefix);
    _placeLabel = std::make_unique<Label>(0, fontHeight * 3, uiManager, kLocationLabelPrefix);
    _actor = _world.getAgentsRegistry().getAgent(0);
}

void ActorInfoView::nextActor() {
    if (_actor && _actor->getID() != _world.getAgentsRegistry().getLastId()) {
        _actor = _world.getAgentsRegistry().getAgent(_actor->getID() + 1);
    }
    updateLabels();
}

void ActorInfoView::prevActor() {
    if (_actor->getID() > 0) {
        _actor = _world.getAgentsRegistry().getAgent(_actor->getID() - 1);
    }
    updateLabels();
}

void ActorInfoView::draw(Window& window) {
    updateLabels();

    _renderTarget.startDrawing(window);

    _nameLabel->draw(window);
    _foodLabel->draw(window);
    _waterLabel->draw(window);
    _placeLabel->draw(window);

    _renderTarget.endDrawing(window);
}

void ActorInfoView::updateLabels() {
    if (!_actor) {
        _actor = _world.getAgentsRegistry().getAgent(0);
    }
    if (!_actor) {
        return;
    }
    _nameLabel->setText(kNameLabelPrefix + _actor->getName());
    std::stringstream ss;
    ss << kFoodLabelPrefix << _actor->getFood();
    _foodLabel->setText(ss.str());
    ss.str("");
    ss << kWaterLabelPrefix << _actor->getWater();
    _waterLabel->setText(ss.str());
    auto actorLocation = _world.getAgentsLocation(*_actor);
    _placeLabel->setText(kLocationLabelPrefix + actorLocation.get_value_or(Core::kPositionInRoute));
}


} // namespace View::Widgets