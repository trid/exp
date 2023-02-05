#ifndef PROCESS_H
#define PROCESS_H

#include <memory>

namespace Core {

class Process {
public:
    virtual ~Process() = default;

    virtual void update(unsigned int delta) = 0;
    [[nodiscard]] virtual bool finished() const = 0;
};

using ProcessPtr = std::unique_ptr<Process>;

} // namespace Core

#endif