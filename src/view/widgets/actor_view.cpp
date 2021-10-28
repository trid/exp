#include <sstream>
#include <SDL2/SDL_ttf.h>

#include "../../ai/actors/agent.h"
#include "../../ai/actors/registry.h"

#include "../view_facade.h"

#include "actor_view.h"
#include "constants.h"
#include "label.h"

extern Core::AI::Actors::AgentsRegistry* g_actorsRegistry;

namespace View::Widgets {

ActorView::ActorView(int x, int y, UIManager& uiManager, ViewFacade& view) :
        Widget(x, y),
        _font(uiManager.getFontsCache().getFont(kFontPath, 20)),
        _view(view),
        _renderTarget(x, y, kActorDataViewWidth, _font.getSize() * 4, view.getWindow())
{
    _renderTarget.setBackgroundColor(10, 10, 50, 100);

    int fontHeight = _font.getSize();
    nameLabel = new Label(0, 0, uiManager, kNameLabelPrefix);
    foodLabel = new Label(0, fontHeight, uiManager, kFoodLabelPrefix);
    waterLabel = new Label(0, fontHeight * 2, uiManager, kWaterLabelPrefix);
    placeLabel = new Label(0, fontHeight * 3, uiManager, kLocationLabelPrefix);
    if (g_actorsRegistry) {
        actor = g_actorsRegistry->getAgent(0);
    }
}

void ActorView::nextActor() {
    if (actor->getID() != g_actorsRegistry->getLastId()) {
        actor = g_actorsRegistry->getAgent(actor->getID() + 1);
    }
    updateLabels();
}

void ActorView::prevActor() {
    if (actor->getID() > 0) {
        actor = g_actorsRegistry->getAgent(actor->getID() - 1);
    }
    updateLabels();
}

void ActorView::draw(Window& window) {
    updateLabels();

    _renderTarget.startDrawing(window);

    nameLabel->draw(window);
    foodLabel->draw(window);
    waterLabel->draw(window);
    placeLabel->draw(window);

    _renderTarget.endDrawing(window);
}

void ActorView::updateLabels() {
    if (!actor && g_actorsRegistry) {
        actor = g_actorsRegistry->getAgent(0);
    }
    if (!actor) {
        return;
    }
    nameLabel->setText(kNameLabelPrefix + actor->getName());
    std::stringstream ss;
    ss << kFoodLabelPrefix << actor->getFood();
    foodLabel->setText(ss.str());
    ss.str("");
    ss << kWaterLabelPrefix << actor->getWater();
    waterLabel->setText(ss.str());
    placeLabel->setText(kLocationLabelPrefix + actor->getPosition());
}

ActorView::~ActorView() {
    delete foodLabel;
    delete waterLabel;
    delete nameLabel;
    delete placeLabel;
}

} // namespace View::Widgets