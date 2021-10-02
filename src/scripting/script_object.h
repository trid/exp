#include <string>
#include <unordered_map>
#include "../parameter.h"

using std::string;
using std::unordered_map;

class ScriptObject {
private:
    unordered_map<string, ParameterPtr> parameters;
public:
    void addParameter(string const &name, ParameterPtr ptr);
    ParameterPtr getParameter(const string &name);
    void deleteParameter(const string& name);
};