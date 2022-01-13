//
// Created by TriD on 13.01.2022.
//

#ifndef EXP_BUTTON_H
#define EXP_BUTTON_H

#include "../image.h"

#include "clickable.h"
#include "widget.h"

namespace View::Widgets {

class Button: public Clickable, public Widget{
public:
    Button(const IntRect& geometry, Image&& image);

    void onClick() override;
    IntRect getGeometry() override;

    void draw(Window& window) override;

private:
    IntRect _geometry;
    Image _image;
};

using ButtonPtr = std::shared_ptr<Button>;

} // namespace View::Widgets

#endif //EXP_BUTTON_H
