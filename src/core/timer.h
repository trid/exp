//
// Created by TriD on 13.01.2022.
//

#ifndef EXP_TIMER_H
#define EXP_TIMER_H

namespace Core {

class Timer {
public:
    Timer();

    unsigned int refresh();
    void setMultiplier(unsigned int multiplier);

private:
    unsigned int _lastTick;
    unsigned int _multiplier{1};
};

} // namespace Core

#endif //EXP_TIMER_H
