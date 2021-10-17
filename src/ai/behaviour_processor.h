//
// Created by TriD on 13.10.2021.
//

#ifndef EXP_BEHAVIOUR_PROCESSOR_H
#define EXP_BEHAVIOUR_PROCESSOR_H

#include <vector>

#include "../process.h"

namespace Core::AI {

namespace Actors {
class Agent;
} // namespace Actors

class BehaviourStep;
class StateManager;

class BehaviourProcessor {
public:
    explicit BehaviourProcessor(StateManager& stateManager, std::vector<Actors::Agent*>& actors);

    void update();
private:
    void processActor(Actors::Agent& actor);
    void processReaction(Actors::Agent& actor);
    void updateBehaviour(Actors::Agent& actor);
    void setBehaviourStep(Actors::Agent& actor, BehaviourStep step);

    StateManager& _stateManager;
    std::vector<Actors::Agent*>& _actors;
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
