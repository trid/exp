//
// Created by TriD on 27.10.2021.
//

#ifndef EXP_RENDER_TARGET_H
#define EXP_RENDER_TARGET_H


#include <SDL2/SDL_render.h>

namespace View {
class Window;
}

namespace View::Widgets {

class RenderTarget {
public:
    explicit RenderTarget(int x, int y, int width, int height, Window& window);
    ~RenderTarget();

    void startDrawing(Window& window);
    void endDrawing(Window& window);

    void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
private:
    SDL_Texture* _texture;
    SDL_Color _backgroundColor;

    int _x;
    int _y;
};

} // namespace View::Widgets

#endif //EXP_RENDER_TARGET_H
