//
// Created by TriD on 13.10.2021.
//

#include "behaviour_processor.h"

#include "../core/world.h"

#include "../scripting/api/agent.h"

#include "agents/agent.h"

#include "constants.h"
#include "state_manager.h"

namespace Core::AI {

BehaviourProcessor::BehaviourProcessor(const StateManager& stateManager, World& world) :
        _stateManager(stateManager),
        _world(world) {}


void BehaviourProcessor::update() {
    for (auto& actor: _world.getAgentsRegistry().getActors()) {
        processActor(actor);
    }
}

void BehaviourProcessor::processActor(Agents::Agent& actor) {
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

void BehaviourProcessor::processReaction(Agents::Agent& actor) {
    for (const auto& globalState: actor.getStatuses()) {
        const auto & statusReactors = actor.getStatusReactors();
        const auto& reactionStateName = statusReactors.find(globalState);
        if (reactionStateName == statusReactors.end()) {
            continue;
        }

        auto reactionBehaviour = _stateManager.getBehaviour(reactionStateName->second);
        if (reactionBehaviour) {
            actor.removeStatus(kIdleStateName);
            actor.setExecutingReaction(true);
            setBehaviourStep(actor, reactionBehaviour->getStartingStep());
            break;
        }
    }
}

void BehaviourProcessor::updateBehaviour(Agents::Agent& actor) {
    boost::optional<BehaviourStep> step = actor.getBehaviourStep();
    while (step) {
        step = step->getTransition(Scripting::API::Agent(_world, actor.getID()));

        if (step) {
            setBehaviourStep(actor, *step);
        }
    }
}

void BehaviourProcessor::setBehaviourStep(Agents::Agent& actor, BehaviourStep step) {
    actor.setBehaviourStep(step);
    step.runStep(Scripting::API::Agent(_world, actor.getID()));
}

BehaviourProcessorProcess::BehaviourProcessorProcess(BehaviourProcessor& behaviourProcessor) : _behaviourProcessor(
        behaviourProcessor) {}

void BehaviourProcessorProcess::update(unsigned int delta) {
    _behaviourProcessor.update();
}

bool BehaviourProcessorProcess::finished() const {
    return false;
}

} // namespace Core::AI
