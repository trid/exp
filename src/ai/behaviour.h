//
// Created by TriD on 13.10.2021.
//

#ifndef EXP_BEHAVIOUR_H
#define EXP_BEHAVIOUR_H

#include <string>

#include <boost/optional.hpp>

#include "sol/sol.hpp"

#include "behaviour_step.h"

namespace Core::AI {

class Behaviour {
public:
    Behaviour(const std::string& name, const sol::table& startingStep);

    BehaviourStep getStartingStep();
private:
    const std::string _name;
    sol::table _startingStep;
};

using BehaviourOpt = boost::optional<Behaviour&>;

} // namespace Core::AI

#endif //EXP_BEHAVIOUR_H
