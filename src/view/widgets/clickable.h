//
// Created by TriD on 13.01.2022.
//

#ifndef EXP_CLICKABLE_H
#define EXP_CLICKABLE_H

#include <memory>

#include "../../utils/rect.h"

namespace View::Widgets {

using IntRect = Core::Utils::Rect<int>;

class Clickable {
public:
    virtual void onClick() = 0;

    virtual IntRect getGeometry() = 0;
};

using ClickablePtr = std::shared_ptr<Clickable>;

}

#endif //EXP_CLICKABLE_H
