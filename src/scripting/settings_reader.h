//
// Created by TriD on 02.10.2021.
//

#ifndef EXP_SETTINGS_READER_H
#define EXP_SETTINGS_READER_H

#include "script_context.h"

namespace Scripting {

class SettingsReader {
public:
    explicit SettingsReader(const std::string& settingsPath);

    [[nodiscard]] int getIntParameter(const std::string& name) const;
    [[nodiscard]] bool getBoolParameter(const std::string& name) const;
    [[nodiscard]] std::string getStringParameter(const std::string& name) const;
private:
    void pushSettingNameToStack(const std::string& name) const;
    void cleanStack() const;

    ScriptContext _settingsScriptContext;
};

} // namespace Scripting

#endif //EXP_SETTINGS_READER_H
