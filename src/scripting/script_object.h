#include <string>
#include <unordered_map>
#include "../parameter.h"

using std::string;
using std::unordered_map;

class ScriptObject {
private:
    unordered_map<string, Core::ParameterPtr> parameters;
public:
    void addParameter(string const &name, Core::ParameterPtr ptr);
    Core::ParameterPtr getParameter(const string &name);
    void deleteParameter(const string& name);
};