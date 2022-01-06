//
// Created by TriD on 07.01.2022.
//

#ifndef EXP_TIMED_PROCESS_CONTROLLER_H
#define EXP_TIMED_PROCESS_CONTROLLER_H

#include <vector>

#include "process.h"

namespace Core {

class TimedProcessController {
public:
    TimedProcessController();

    void addProcess(ProcessPtr ptr);
    void update();

private:
    std::vector<ProcessPtr> _processes;

    unsigned int _lastTick;
};

} // namespace Core

#endif //EXP_TIMED_PROCESS_CONTROLLER_H
