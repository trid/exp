#ifndef MAP_OBJECT_VIEW_H
#define MAP_OBJECT_VIEW_H

#include <string>
#include <memory>

#include <SDL2/SDL_render.h>

namespace Core {
class Location;
} // namespace Core

namespace View {

class MapObjectView {
public:
    explicit MapObjectView(const Core::Location& location, SDL_Texture* image);

    void draw(SDL_Renderer* renderer);

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

private:
    SDL_Texture* _image;
    const Core::Location& _location;
};

using MapObjectUPtr = std::unique_ptr<MapObjectView>;

} // namespace View

#endif // MAP_OBJECT_VIEW_H
