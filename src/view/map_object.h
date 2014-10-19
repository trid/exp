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

    int getX() const {
        return x;
    }

    void setX(int x) {
        MapObject::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        MapObject::y = y;
    }
};

typedef std::shared_ptr<MapObject> MapObjectPtr;

#endif