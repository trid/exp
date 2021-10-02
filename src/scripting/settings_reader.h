//
// Created by TriD on 02.10.2021.
//

#ifndef EXP_SETTINGS_READER_H
#define EXP_SETTINGS_READER_H

#include "script_context.h"

class SettingsReader {
public:
    SettingsReader();

    [[nodiscard]] int getIntParameter(const string& name) const;
    [[nodiscard]] bool getBoolParameter(const string& name) const;
    [[nodiscard]] string getStringParameter(const string& name) const;
private:
    void pushSettingNameToStack(string const &name) const;
    void cleanStack() const;

    ScriptContext _settingsScriptContext;
};


#endif //EXP_SETTINGS_READER_H
