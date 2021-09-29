#include <SDL2/SDL_image.h>
#include "map_object_view.h"
#include "../location.h"

MapObjectView::MapObjectView() {
}

MapObjectView::~MapObjectView() {
}

void MapObjectView::draw(SDL_Renderer *renderer) {
    SDL_Rect rect;
    rect.x = getX();
    rect.y = getY();
    SDL_QueryTexture(image, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, image, nullptr, &rect);
}

int MapObjectView::getX() const {
    return location->getXPos();
}

int MapObjectView::getY() const {
    return location->getYPos();
}
