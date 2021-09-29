#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <lua5.1/lua.hpp>

using std::string;

class ScriptManager;

class Settings {
public:
    explicit Settings(ScriptManager& scriptManager);

    int getIntParameter(const string& name) const;
    bool getBoolParameter(const string& name) const;
    string getStringParameter(const string& name) const;

private:
    void pushSettingToStack(string const &name) const;

    ScriptManager& _scriptManager;
};

#endif // SETTINGS_H