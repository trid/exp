#include <string>
#include <unordered_map>

#include "action.h"

using std::string;
using std::unordered_map;

class ActionManager {
private:
    ActionManager();
    ~ActionManager();
    unordered_map<string, VirtualActionFactory*> actionMap;
public:
    static ActionManager& getInstance() {
        static ActionManager am;
        return am;
    }

    ActionPtr getAction(const string& action, Actor* actor);
};