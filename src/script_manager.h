#include <string>

#include "lua.hpp"

using std::string;

class ScriptManager {
private:
    ScriptManager();
    lua_State* state;
public:
    static ScriptManager& getInstance() {
        static ScriptManager sm;
        return sm;
    }

    void loadScript(const string& path);
    void registerFunctions();
    void registerFunction(const string& name, lua_CFunction function);
    lua_State* getState() {
        return state; }
};