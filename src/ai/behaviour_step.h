//
// Created by TriD on 13.10.2021.
//

#ifndef EXP_BEHAVIOUR_STEP_H
#define EXP_BEHAVIOUR_STEP_H

#include <limits>

#include <boost/optional.hpp>

#include "sol/sol.hpp"

namespace Scripting::API {
class Agent;
} // namespace Scripting::API

namespace Core::AI {

class BehaviourStep {
public:
    explicit BehaviourStep(const sol::table& step);

    void runStep(Scripting::API::Agent&& actor) const;
    boost::optional<BehaviourStep> getTransition(Scripting::API::Agent&& actor) const;
private:
    sol::table step;
};

using BehaviourStepOpt = boost::optional<BehaviourStep>;

} // namespace Core::AI

#endif //EXP_BEHAVIOUR_STEP_H
