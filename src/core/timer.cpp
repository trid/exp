//
// Created by TriD on 13.01.2022.
//

#include "timer.h"

#include <SDL2/SDL_timer.h>

namespace Core {

Timer::Timer(): _lastTick(SDL_GetTicks()) {

}

unsigned int Timer::refresh() {
    const auto currentTime = SDL_GetTicks();
    const auto delta = currentTime - _lastTick;
    _lastTick = currentTime;
    return delta * _multiplier;
}

void Timer::setMultiplier(unsigned int multiplier) {
    _multiplier = multiplier;
}
} // namespace Core