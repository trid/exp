//
// Created by TriD on 13.10.2021.
//

#include "behaviour_processor.h"

#include "actors/agent.h"
#include "constants.h"
#include "state_manager.h"

namespace Core::AI {

BehaviourProcessor::BehaviourProcessor(StateManager& stateManager, std::vector<Actors::Agent*>& actors) :
        _stateManager(stateManager),
        _actors(actors) {}


void BehaviourProcessor::update() {
    for (auto& actor: _actors) {
        processActor(*actor);
    }
}

void BehaviourProcessor::processActor(Actors::Agent& actor) {
    if (!actor.getStatuses().empty() && !actor.isExecutingReaction()) {
        processReaction(actor);
    }

    if (!actor.getBehaviourStep()) {
        const auto& defaultBehaviourStateName = actor.getStatusReactors().at(kNoStateStateName);
        auto behaviour = _stateManager.getBehaviour(defaultBehaviourStateName);
        if (behaviour) {
            setBehaviourStep(actor, behaviour->getStartingStep());
        }
    }

    updateBehaviour(actor);
}

void BehaviourProcessor::processReaction(Actors::Agent& actor) {
    for (const auto& globalState: actor.getStatuses()) {
        const auto& reactionStateName = actor.getStatusReactors().at(globalState);
        auto reactionBehaviour = _stateManager.getBehaviour(reactionStateName);
        if (reactionBehaviour) {
            actor.setExecutingReaction(true);
            setBehaviourStep(actor, reactionBehaviour->getStartingStep());
            break;
        }
    }
}

void BehaviourProcessor::updateBehaviour(Actors::Agent& actor) {
    boost::optional<BehaviourStep> step = actor.getBehaviourStep();
    while (step) {
        step = step->getTransition(actor);

        if (step) {
            setBehaviourStep(actor, *step);
        }
    }
}

void BehaviourProcessor::setBehaviourStep(Actors::Agent& actor, BehaviourStep step) {
    actor.setBehaviourStep(step);
    step.runStep(actor);
}

BehaviourProcessorProcess::BehaviourProcessorProcess(BehaviourProcessor& behaviourProcessor) : _behaviourProcessor(
        behaviourProcessor) {}

void BehaviourProcessorProcess::update(int delta) {
    _behaviourProcessor.update();
}

bool BehaviourProcessorProcess::finished() {
    return false;
}

} // namespace Core::AI
