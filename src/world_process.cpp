//
// Created by TriD on 01.11.2021.
//

#include "world_process.h"

#include "world.h"

namespace Core {

WorldProcess::WorldProcess(World& world) :
        _world(world) {

}

void WorldProcess::update(unsigned int delta) {
    _world.update(delta);
}

bool WorldProcess::finished() {
    return false;
}

} // namespace Core