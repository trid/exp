#ifndef MAP_OBJECT_H
#define MAP_OBJECT_H

#include <string>
#include <memory>
#include <SDL_render.h>

using std::string;

class MapObjectView {
private:
    int x, y;
    SDL_Texture* image;
public:
    MapObjectView(int x, int y, const string& path);
    ~MapObjectView();
    void draw(SDL_Renderer* renderer);

    int getX() const {
        return x;
    }

    void setX(int x) {
        MapObjectView::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        MapObjectView::y = y;
    }
};

typedef std::shared_ptr<MapObjectView> MapObjectPtr;

#endif
