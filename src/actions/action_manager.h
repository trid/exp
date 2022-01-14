#ifndef ACTION_MANAGER_H
#define ACTION_MANAGER_H

#include <string>
#include <unordered_map>

#include "action.h"

namespace Core::Actions {

class ActionManager {
public:
    explicit ActionManager(Core::World& world);

    ActionPtr getAction(const std::string& action, AI::Agents::Agent& actor);
private:
    Core::World& _world;

    std::unordered_map<std::string, std::unique_ptr<VirtualActionFactory>> _actionMap;
};

} // namespace Core::Actions

#endif // ACTION_MANAGER_H