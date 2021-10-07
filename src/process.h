#ifndef PROCESS_H
#define PROCESS_H

#include <memory>

namespace Core {

class Process {
public:
    virtual void update(int delta) = 0;
    virtual bool finished() = 0;
};

typedef std::shared_ptr<Process> ProcessPtr;

} // namespace Core

#endif