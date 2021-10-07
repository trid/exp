#ifndef MAP_OBJECT_H
#define MAP_OBJECT_H

#include <string>
#include <memory>
#include <SDL2/SDL_render.h>

using std::string;

namespace Core {
class Location;
} // namespace Core

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

typedef std::shared_ptr<MapObjectView> MapObjectPtr;

#endif
