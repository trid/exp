//
// Created by TriD on 25.10.2021.
//

#ifndef EXP_LOG_VIEW_RENDERER_H
#define EXP_LOG_VIEW_RENDERER_H

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

#include <deque>
#include <string>

namespace View {
class Window;
}

namespace View::Widgets {

class UIManager;

class LogViewRenderer {
public:
    explicit LogViewRenderer(const UIManager& uiManager);

    void draw(int x, int y, const std::deque<std::string>& messages, Window& window);
    void enforceUpdate();
private:
    const UIManager& _uiManager;

    SDL_Color _textColor{255, 255, 255, 255};
    bool _dirty = true;
    SDL_Texture* _surface = nullptr;
    void updateSurface(const std::deque<std::string>& messages, const Window& window, SDL_Renderer* renderer);
    void drawMessages(int x, int y, SDL_Renderer* renderer) const;
    void
    drawMessagesToSurface(const std::deque<std::string>& messages, SDL_Renderer* renderer, int height,
                          int startHeight) const;
};

}

#endif //EXP_LOG_VIEW_RENDERER_H
