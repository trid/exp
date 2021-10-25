//
// Created by TriD on 25.10.2021.
//

#ifndef EXP_FONT_H
#define EXP_FONT_H


#include <SDL2/SDL_ttf.h>

class Font {
public:
    explicit Font(TTF_Font* font);

    [[nodiscard]] int getSize() const;
    [[nodiscard]] TTF_Font* getImpl() const;
private:
    TTF_Font* _font;
};


#endif //EXP_FONT_H
