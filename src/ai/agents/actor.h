//
// Created by TriD on 18.10.2021.
//

#ifndef EXP_ACTOR_H
#define EXP_ACTOR_H

#include <unordered_set>

#include "../../actions/action.h"

#include "../behaviour_step.h"

namespace Core::AI::Agents {

class Actor {
public:
    BehaviourStepOpt getBehaviourStep();
    void setBehaviourStep(BehaviourStepOpt step);

    void addStatus(const std::string& stateName);
    void removeStatus(std::string const& stateName);
    const std::unordered_set<std::string>& getStatuses() const;
    const std::unordered_map<std::string, std::string>& getStatusReactors() const;

    void setReactor(const std::string& stateName, const std::string& reactionState);

    void setAction(Core::Actions::ActionPtr action);
    void removeAction();
    bool hasAction() const;
    bool isExecutingReaction() const;
    void setExecutingReaction(bool executingReaction);
private:
    BehaviourStepOpt _step = boost::none;
    bool _executingReaction = false;
    std::unordered_set<std::string> _statuses;
    std::unordered_map<std::string, std::string> _statusReactors;
    Core::Actions::ActionPtr _currentAction;
};

} // namespace Core::AI::Agents

#endif //EXP_ACTOR_H
