#include <string>
#include <unordered_map>

#include "state.h"
#include "lua.hpp"

class StateManager {
private:
    std::unordered_map<std::string, State*> states;
    void registerStates();
    StateManager();
public:
    static StateManager& getInstance() {
        static StateManager sm;
        return sm;
    }

    State* getState(const std::string& name);

    void registerScriptedStates();
    void registerScriptedState(char const *tableName, char const *stateName);
};