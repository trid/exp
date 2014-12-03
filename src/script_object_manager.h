#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

class ScriptObject;

class ScriptObjectManager {
private:
    ScriptObjectManager(){}
    unordered_map<string, ScriptObject*> objects;
public:
    static ScriptObjectManager& getInstance() {
        static ScriptObjectManager scriptObjectManager;
        return scriptObjectManager;
    }

    ScriptObject* getItem(const string& name);
    void addItem(const string& name, ScriptObject* item);
    void deleteItem(const string& name);
};