#include <SDL_image.h>
#include "map_object_view.h"
#include "view.h"

MapObjectView::MapObjectView(int x, int y, string const &path): x(x), y(y) {
    image = IMG_LoadTexture(View::getView().getRenderer(), path.c_str());
}

MapObjectView::~MapObjectView() {
    SDL_DestroyTexture(image);
}

void MapObjectView::draw(SDL_Renderer *renderer) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(image, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, image, nullptr, &rect);
}
