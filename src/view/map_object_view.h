#ifndef MAP_OBJECT_H
#define MAP_OBJECT_H

#include <string>
#include <memory>
#include <SDL_render.h>

using std::string;

class Location;

class MapObjectView {
friend class SceneObjectManager;
private:
    SDL_Texture* image;
    Location* location;
public:
    MapObjectView();
    ~MapObjectView();
    void draw(SDL_Renderer* renderer);

    int getX() const;
    int getY() const;
};

typedef std::shared_ptr<MapObjectView> MapObjectPtr;

#endif
