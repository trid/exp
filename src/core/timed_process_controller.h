//
// Created by TriD on 07.01.2022.
//

#ifndef EXP_TIMED_PROCESS_CONTROLLER_H
#define EXP_TIMED_PROCESS_CONTROLLER_H

#include <vector>

#include "process.h"
#include "timer.h"


namespace Core {

class TimedProcessController {
public:
    TimedProcessController(Timer& timer);

    void addProcess(ProcessPtr ptr);
    void update();

private:
    std::vector<ProcessPtr> _processes;

    Timer& _timer;
    unsigned int _lag{0};
};

} // namespace Core

#endif //EXP_TIMED_PROCESS_CONTROLLER_H
