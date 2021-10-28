//
// Created by TriD on 28.10.2021.
//

#ifndef EXP_LABEL_RENDERER_H
#define EXP_LABEL_RENDERER_H


#include <string>

#include <SDL2/SDL_render.h>
#include "../../font.h"

namespace View {
class Window;
}

namespace View::Widgets {

class LabelRenderer {
public:
    LabelRenderer(int x, int y, std::string&& text, Font&& font);

    void setText(std::string&& text);
    void draw(Window& window);
private:
    std::string _text;
    SDL_Texture* _renderedText = nullptr;
    SDL_Color _textColor = {255, 255, 255, 255 };
    Font _font;

    int _x;
    int _y;

    bool _dirty = true;
};

}

#endif //EXP_LABEL_RENDERER_H
