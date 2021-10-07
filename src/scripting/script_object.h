#include <string>
#include <unordered_map>
#include "../parameter.h"

namespace Scripting {

class ScriptObject {
private:
    std::unordered_map <std::string, Core::ParameterPtr> parameters;
public:
    void addParameter(std::string const& name, Core::ParameterPtr ptr);
    Core::ParameterPtr getParameter(const std::string& name);
    void deleteParameter(const std::string& name);
};

} // namespace Scripting