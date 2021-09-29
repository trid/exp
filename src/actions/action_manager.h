#ifndef ACTION_MANAGER_H
#define ACTION_MANAGER_H

#include <string>
#include <unordered_map>

#include "action.h"

using std::string;
using std::unordered_map;

class ActionManager {
public:
    ActionManager(World& world);
    ~ActionManager();

    ActionPtr getAction(const string& action, Actor* actor);
private:
    World& _world;

    unordered_map<string, VirtualActionFactory*> _actionMap;
};

#endif // ACTION_MANAGER_H