//
// Created by TriD on 25.10.2021.
//

#include "font.h"

Font::Font(TTF_Font* font) : _font(font) {}

int Font::getSize() const {
    return TTF_FontHeight(_font);
}

TTF_Font* Font::getImpl() const {
    return _font;
}
