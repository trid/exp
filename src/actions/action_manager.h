#ifndef ACTION_MANAGER_H
#define ACTION_MANAGER_H

#include <string>
#include <unordered_map>

#include "action.h"

namespace Core::Actions {

class ActionManager {
public:
    ActionManager(Core::World& world);
    ~ActionManager();

    ActionPtr getAction(const std::string& action, AI::Actors::Actor* actor);
private:
    Core::World& _world;

    std::unordered_map<std::string, VirtualActionFactory*> _actionMap;
};

} // namespace Core::Actions

#endif // ACTION_MANAGER_H