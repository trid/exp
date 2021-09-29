#ifndef WIDGET_H
#define WIDGET_H

#include <memory>
#include <SDL2/SDL_render.h>

class Widget {
private:
    int x, y;
protected:
    SDL_Texture* surface = nullptr;
public:
    Widget();
    Widget(int x, int y);
    virtual ~Widget();
    virtual void draw(SDL_Renderer*) = 0;

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
};

typedef std::shared_ptr<Widget> WidgetPtr;

#endif