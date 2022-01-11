#include "map_object_view.h"

#include "../location.h"

namespace View {

MapObjectView::MapObjectView(const Core::Location& location, SDL_Texture* image): _location(location), _image(image) {
}

void MapObjectView::draw(SDL_Renderer* renderer) {
    SDL_Rect rect;
    rect.x = getX();
    rect.y = getY();
    SDL_QueryTexture(_image, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, _image, nullptr, &rect);
}

int MapObjectView::getX() const {
    return _location.getXPos();
}

int MapObjectView::getY() const {
    return _location.getYPos();
}

} // namespace View