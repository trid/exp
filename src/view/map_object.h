#ifndef MAP_OBJECT_H
#define MAP_OBJECT_H

#include <string>
#include <memory>
#include <SDL_render.h>

using std::string;

class MapObject {
private:
    int x, y;
    SDL_Texture* image;
public:
    MapObject(int x, int y, const string& path);
    ~MapObject();
    void draw(SDL_Renderer* renderer);
};

typedef std::shared_ptr<MapObject> MapObjectPtr;

#endif