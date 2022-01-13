//
// Created by TriD on 20.10.2021.
//

#ifndef EXP_IMAGE_H
#define EXP_IMAGE_H

#include <string>

#include "SDL2/SDL.h"

namespace View {

class Window;

class Image {
public:
    explicit Image(const std::string& filePath, const Window& window);
    Image(const Image&) = delete;
    Image(Image&& other) noexcept;
    ~Image();

    Image& operator=(const Image&) = delete;
    Image& operator=(Image&& other) noexcept;

    void draw(int x, int y, int w, int h, Window& window);
    void draw(int x, int y, Window& window);
    void draw(Window& window);
private:
    SDL_Texture* _texture;
};

}

#endif //EXP_IMAGE_H
