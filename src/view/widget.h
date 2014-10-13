#ifndef WIDGET_H
#define WIDGET_H

#include <memory>
#include <SDL_render.h>

class Widget {
private:
    int x, y;
protected:
    SDL_Texture* surface = nullptr;
public:
    Widget(int x, int y): x(x), y(y) {}
    virtual void draw(SDL_Renderer*) = 0;

    int getX() const { return x; }
    void setX(int x) { Widget::x = x; }
    int getY() const { return y; }
    void setY(int y) { Widget::y = y; }
};

typedef std::shared_ptr<Widget> WidgetPtr;

#endif