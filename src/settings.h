#include <string>
#include <lua.hpp>

using std::string;

class Settings {
private:
    Settings();

public:
    static Settings& getSettings() {
        static Settings settings;
        return settings;
    }

    int getIntParameter(const string& name);
    bool getBoolParameter(const string& name);
    const string & getStringParameter(const string& name);

    void pushSettingToStack(string const &name);
};