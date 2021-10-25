#ifndef WIDGET_H
#define WIDGET_H

#include <memory>
#include <SDL2/SDL_render.h>
#include "../window.h"

namespace View::Widgets {

class Widget {
private:
    int x, y;
protected:
    SDL_Texture* surface = nullptr;
public:
    Widget();
    Widget(int x, int y);
    virtual ~Widget();
    virtual void draw(View::Window&) = 0;

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
};

typedef std::shared_ptr<Widget> WidgetPtr;

} // namespace View::Widgets

#endif // WIDGET_H