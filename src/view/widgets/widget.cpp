#include "widget.h"

namespace View::Widgets {

Widget::Widget() :
        x(0), y(0) {

}

Widget::Widget(int x, int y) : x(x), y(y) {}

int Widget::getX() const { return x; }

void Widget::setX(int x) { Widget::x = x; }

int Widget::getY() const { return y; }

void Widget::setY(int y) { Widget::y = y; }

} // namespace View::Widgets