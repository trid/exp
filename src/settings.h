#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <lua5.1/lua.hpp>

using std::string;

class ScriptManager;

class Settings {
public:
    Settings(ScriptManager& scriptManager);

    int getIntParameter(const string& name);
    bool getBoolParameter(const string& name);
    string getStringParameter(const string& name);

    void pushSettingToStack(string const &name);

private:
    ScriptManager& _scriptManager;
};

#endif // SETTINGS_H