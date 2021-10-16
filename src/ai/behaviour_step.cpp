//
// Created by TriD on 13.10.2021.
//

#include "behaviour_step.h"

#include "actors/actor.h"
#include "constants.h"

namespace Core::AI {

BehaviourStep::BehaviourStep(const sol::table& step) : step(step) {}

void BehaviourStep::runStep(Actors::Actor& actor) {
    sol::optional<sol::function> runFunctionOpt = step[kRunFunctionName];
    if (runFunctionOpt) {
        auto& runFunction = *runFunctionOpt;
        if (sol::optional<sol::table> metatable = step[sol::metatable_key]) {
            runFunction(step, actor);
        } else {
            runFunction(actor);
        }
    }
}

boost::optional<BehaviourStep> BehaviourStep::getTransition(Actors::Actor& actor) {
    sol::function transitionFunction = step[kTransitionFunctionName];
    sol::optional<sol::table> transitionStep;

    if (static_cast<sol::optional<sol::table>>(step[sol::metatable_key])) {
        transitionStep = static_cast<sol::optional<sol::table>>(transitionFunction(step, actor));
    } else {
        transitionStep = static_cast<sol::optional<sol::table>>(transitionFunction(actor));
    }

    if (transitionStep) {
        return BehaviourStep(*transitionStep);
    }
    return boost::none;
}

} // namespace Core::AI