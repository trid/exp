#include "map_object_view.h"

#include "../core/location.h"

#include "image.h"

namespace View {

MapObjectView::MapObjectView(const Core::Location& location, Image& image): _location(location), _image(image) {
}

void MapObjectView::draw(const Window& window) {
    _image.draw(getX(), getY(), window);
}

int MapObjectView::getX() const {
    return _location.getXPos();
}

int MapObjectView::getY() const {
    return _location.getYPos();
}

} // namespace View