//
// Created by TriD on 07.01.2022.
//

#include "timed_process_controller.h"

#include <algorithm>

#include "constants.h"


namespace Core {

TimedProcessController::TimedProcessController(Timer& timer) : _timer(timer) {}

void TimedProcessController::addProcess(ProcessPtr&& ptr) {
    _processes.push_back(std::move(ptr));
}

void TimedProcessController::update() {
    _lag += _timer.refresh();

    while (_lag >= kTimePerUpdateMillis) {
        for (auto& process: _processes) {
            process->update(kTimePerUpdateMillis);
        }

        auto iter = std::remove_if(_processes.begin(), _processes.end(),
                                   [](const ProcessPtr& processPtr) { return processPtr->finished(); });
        _processes.erase(iter, _processes.end());
        _lag -= kTimePerUpdateMillis;
    }
}

} // namespace Core
