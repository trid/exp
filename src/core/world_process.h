//
// Created by TriD on 01.11.2021.
//

#ifndef EXP_WORLD_PROCESS_H
#define EXP_WORLD_PROCESS_H

#include "process.h"

namespace Core {

class World;

class WorldProcess : public Process {
public:
    explicit WorldProcess(World& world);

    void update(unsigned int delta) override;

    bool finished() const override;

private:
    World& _world;
};

} // namespace Core

#endif //EXP_WORLD_PROCESS_H
