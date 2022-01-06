//
// Created by TriD on 07.01.2022.
//

#include "timed_process_controller.h"

#include <algorithm>

#include <SDL2/SDL_timer.h>

Core::TimedProcessController::TimedProcessController() : _lastTick(SDL_GetTicks()) {

}

void Core::TimedProcessController::addProcess(Core::ProcessPtr ptr) {
    _processes.push_back(ptr);
}

void Core::TimedProcessController::update() {
    auto currentTime = SDL_GetTicks();
    auto delta = currentTime - _lastTick;
    _lastTick = currentTime;
    for (ProcessPtr process: _processes) {
        process->update(delta);
    }

    auto iter = std::remove_if(_processes.begin(), _processes.end(),
                               [](const ProcessPtr& processPtr) { return processPtr->finished(); });
    _processes.erase(iter, _processes.end());
}

