//
// Created by TriD on 07.01.2022.
//

#include "timed_process_controller.h"

#include <algorithm>

#include <SDL2/SDL_timer.h>

#include "constants.h"

namespace Core {

TimedProcessController::TimedProcessController() : _lastTick(SDL_GetTicks()) {

}

void TimedProcessController::addProcess(Core::ProcessPtr ptr) {
    _processes.push_back(ptr);
}

void TimedProcessController::update() {
    auto currentTime = SDL_GetTicks();
    auto delta = currentTime - _lastTick;
    _lastTick = currentTime;
    _lag += delta;

    while (_lag >= kTimePerUpdateMillis) {
        for (ProcessPtr process: _processes) {
            process->update(kTimePerUpdateMillis);
        }

        auto iter = std::remove_if(_processes.begin(), _processes.end(),
                                   [](const ProcessPtr& processPtr) { return processPtr->finished(); });
        _processes.erase(iter, _processes.end());
        _lag -= kTimePerUpdateMillis;
    }
}

} // namespace Core
