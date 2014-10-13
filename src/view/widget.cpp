#include "widget.h"

Widget::~Widget() {
    if (surface) {
        SDL_DestroyTexture(surface);
    }
}
