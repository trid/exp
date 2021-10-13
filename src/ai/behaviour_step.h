//
// Created by TriD on 13.10.2021.
//

#ifndef EXP_BEHAVIOUR_STEP_H
#define EXP_BEHAVIOUR_STEP_H

#include <boost/optional.hpp>

#include "sol/sol.hpp"

namespace Core::AI {

class Actor;



class BehaviourStep {
public:
    explicit BehaviourStep(const sol::table& step);

    void runStep(Actor& actor);
    boost::optional<BehaviourStep> getTransition(Actor& actor);
private:
    sol::table step;
};

using BehaviourStepOpt = boost::optional<BehaviourStep>;

} // namespace Core::AI

#endif //EXP_BEHAVIOUR_STEP_H
