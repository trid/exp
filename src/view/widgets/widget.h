#ifndef WIDGET_H
#define WIDGET_H

#include <memory>
#include <SDL2/SDL_render.h>
#include "../window.h"

namespace View::Widgets {

class Widget {
public:
    Widget();
    Widget(int x, int y);
    virtual ~Widget() = default;
    virtual void draw(View::Window&) = 0;

    [[nodiscard]] int getX() const;
    void setX(int x);
    [[nodiscard]] int getY() const;
    void setY(int y);
private:
    int x, y;
};

typedef std::shared_ptr<Widget> WidgetPtr;

} // namespace View::Widgets

#endif // WIDGET_H