#include <unordered_map>
#include <string>

namespace Scripting {

class ScriptObject;

class ScriptObjectManager {
public:
    ScriptObjectManager();

    ScriptObject* getItem(const std::string& name);
    void addItem(const std::string& name, ScriptObject* item);
    void deleteItem(const std::string& name);
private:
    std::unordered_map<std::string, ScriptObject*> objects;
};

} // namespace Scripting