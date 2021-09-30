#include <sstream>
#include <SDL2/SDL_ttf.h>

#include "../../ai/actor.h"
#include "../../ai/registry.h"

#include "../view.h"

#include "actor_view.h"
#include "constants.h"
#include "label.h"

using std::stringstream;

ActorsRegistry* g_actorsRegistry = nullptr;

ActorView::ActorView(int x, int y, UIManager& uiManager, View& view) :
        Widget(x, y),
        _uiManager(uiManager),
        _view(view)
{
    int fontHeight = TTF_FontHeight(_uiManager.getFont());
    nameLabel = new Label(0, 0, _uiManager, kNameLabelPrefix);
    foodLabel = new Label(0, fontHeight, _uiManager, kFoodLabelPrefix);
    waterLabel = new Label(0, fontHeight * 2, _uiManager, kWaterLabelPrefix);
    placeLabel = new Label(0, fontHeight * 3, _uiManager, kLocationLabelPrefix);
    if (g_actorsRegistry) {
        actor = g_actorsRegistry->getActor(0);
    }
}

void ActorView::nextActor() {
    if (actor->getID() != g_actorsRegistry->getLastId()) {
        actor = g_actorsRegistry->getActor(actor->getID() + 1);
    }
    updateLabels();
}

void ActorView::prevActor() {
    if (actor->getID() > 0) {
        actor = g_actorsRegistry->getActor(actor->getID() - 1);
    }
    updateLabels();
}

void ActorView::draw(SDL_Renderer *renderer) {
    updateLabels();

    //TODO: move it to constructor after moving UI item out from View class
    if (!surface) {
        int fontHeight = TTF_FontHeight(_uiManager.getFont());
        surface = SDL_CreateTexture(renderer, _view.getScreenPixelFormat(), SDL_TEXTUREACCESS_TARGET, 200, fontHeight * 4);
        SDL_SetTextureBlendMode(surface, SDL_BLENDMODE_BLEND);
    }

    SDL_SetRenderTarget(renderer, surface);
    SDL_SetRenderDrawColor(renderer, 10, 10, 50, 100);
    SDL_RenderClear(renderer);
    nameLabel->draw(renderer);
    foodLabel->draw(renderer);
    waterLabel->draw(renderer);
    placeLabel->draw(renderer);
    SDL_SetRenderTarget(renderer, nullptr);
    SDL_Rect rect;
    rect.x = getX();
    rect.y = getY();
    SDL_QueryTexture(surface, nullptr, nullptr, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, surface, nullptr, &rect);
}

void ActorView::updateLabels() {
    if (!actor && g_actorsRegistry) {
        actor = g_actorsRegistry->getActor(0);
    }
    if (!actor) {
        return;
    }
    nameLabel->setText(kNameLabelPrefix + actor->getName());
    stringstream ss;
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
