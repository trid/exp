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
    friend class SceneObjectManager;

private:
    SDL_Texture* image;
    Core::Location* location;
public:
    MapObjectView();
    ~MapObjectView();
    void draw(SDL_Renderer* renderer);

    int getX() const;
    int getY() const;
};

using MapObjectPtr = std::shared_ptr<MapObjectView>;

} // namespace View

#endif // MAP_OBJECT_VIEW_H
