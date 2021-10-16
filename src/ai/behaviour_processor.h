//
// Created by TriD on 13.10.2021.
//

#ifndef EXP_BEHAVIOUR_PROCESSOR_H
#define EXP_BEHAVIOUR_PROCESSOR_H

#include <vector>

#include "../process.h"

namespace Core::AI {

namespace Actors {
class Actor;
} // namespace Actors

class BehaviourStep;
class StateManager;

class BehaviourProcessor {
public:
    explicit BehaviourProcessor(StateManager& stateManager, std::vector<Actors::Actor*>& actors);

    void update();
private:
    void processActor(Actors::Actor& actor);
    void processReaction(Actors::Actor& actor);
    void updateBehaviour(Actors::Actor& actor);
    void setBehaviourStep(Actors::Actor& actor, BehaviourStep step);

    StateManager& _stateManager;
    std::vector<Actors::Actor*>& _actors;
};

class BehaviourProcessorProcess: public Process {
public:
    explicit BehaviourProcessorProcess(BehaviourProcessor& behaviourProcessor);

    void update(int delta) override;
    bool finished() override;
private:
    BehaviourProcessor& _behaviourProcessor;
};

} // namespace Core::AI

#endif //EXP_BEHAVIOUR_PROCESSOR_H
