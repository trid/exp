//
// Created by TriD on 07.01.2022.
//

#ifndef EXP_AGENTS_UPDATER_H
#define EXP_AGENTS_UPDATER_H

#include "../../process.h"

#include "registry.h"

namespace Core::AI::Actors {

class AgentNeedsUpdater : public Core::Process {
public:
    explicit AgentNeedsUpdater(AgentsRegistry& actorRegistry);

    void update(unsigned int delta) override;
    bool finished() override;

private:
    void updateNeeds(Agent* actor) const;

    unsigned int _time = 0;
    unsigned int _interval = 500;

    AgentsRegistry& _actorRegistry;
};

} // namespace Core::AI::Actors

#endif //EXP_AGENTS_UPDATER_H