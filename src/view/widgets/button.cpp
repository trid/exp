//
// Created by TriD on 13.01.2022.
//

#include "button.h"

namespace View::Widgets {

Button::Button(const View::Widgets::IntRect& geometry, View::Image&& image):
    _geometry(geometry),
    _image(std::move(image)) {

}

void Button::onClick() {

}

IntRect Button::getGeometry() {
    return _geometry;
}

void Button::draw(Window& window) {
    _image.draw(_geometry.x, _geometry.y, _geometry.width, _geometry.height, window);
}

} // namespace View::Widgets