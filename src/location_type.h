#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class LocationType {
friend class LocationTypeManager;
private:
    string name;
    unordered_set<string> actions;
public:
    LocationType(const string& name): name(name){}

    const string& getName() { return name; }
    const unordered_set<string>& getActions() { return actions; }
};