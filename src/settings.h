#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

#include "lua5.1/lua.hpp"

#include "script_context.h"

using std::string;

class Settings {
public:
    explicit Settings();

    [[nodiscard]] int getIntParameter(const string& name) const;
    [[nodiscard]] bool getBoolParameter(const string& name) const;
    [[nodiscard]] string getStringParameter(const string& name) const;

private:
    void pushSettingToStack(string const &name) const;

    ScriptContext _scriptManager;
};

#endif // SETTINGS_H