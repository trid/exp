//
// Created by TriD on 13.01.2022.
//

#ifndef EXP_RECT_UTILS_H
#define EXP_RECT_UTILS_H

#include "rect.h"

namespace Core::Utils {

template<typename T>
bool isInRect(T posX, T posY, const Core::Utils::Rect<T>& rect) {
    if (posX < rect.x) return false;
    if (posX > rect.x + rect.width) return false;
    if (posY < rect.y) return false;
    if (posY > rect.y + rect.height) return false;
    return true;
}

}

#endif //EXP_RECT_UTILS_H
