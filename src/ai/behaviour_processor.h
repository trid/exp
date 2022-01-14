//
// Created by TriD on 13.10.2021.
//

#ifndef EXP_BEHAVIOUR_PROCESSOR_H
#define EXP_BEHAVIOUR_PROCESSOR_H

#include <vector>

#include "../core/process.h"

namespace Core {
class World;
} // namespace Core

namespace Core::AI {

namespace Actors {
class Agent;
} // namespace Actors

class BehaviourStep;
class StateManager;

class BehaviourProcessor {
public:
    explicit BehaviourProcessor(const StateManager& stateManager, World& world);

    void update();
private:
    void processActor(Actors::Agent& actor);
    void processReaction(Actors::Agent& actor);
    void updateBehaviour(Actors::Agent& actor);
    void setBehaviourStep(Actors::Agent& actor, BehaviourStep step);

    const StateManager& _stateManager;
    World& _world;
};

class BehaviourProcessorProcess: public Process {
public:
    explicit BehaviourProcessorProcess(BehaviourProcessor& behaviourProcessor);

    void update(unsigned int delta) override;
    bool finished() const override;
private:
    BehaviourProcessor& _behaviourProcessor;
};

} // namespace Core::AI

#endif //EXP_BEHAVIOUR_PROCESSOR_H
