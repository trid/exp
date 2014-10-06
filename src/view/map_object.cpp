#include <SDL_image.h>
#include "map_object.h"
#include "view.h"

MapObject::MapObject(int x, int y, string const &path): x(x), y(y) {
    image = IMG_LoadTexture(View::getView().getRenderer(), path.c_str());
}

MapObject::~MapObject() {
    SDL_DestroyTexture(image);
}

void MapObject::draw(SDL_Renderer *renderer) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_QueryTexture(image, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, image, nullptr, &rect);
}
