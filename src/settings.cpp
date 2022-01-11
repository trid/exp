#include "settings.h"

#include "constants.h"

#include "scripting/settings_reader.h"

namespace Core {

Settings::Settings() {
    Scripting::SettingsReader settingsReader;
    _screenWidth = settingsReader.getIntParameter(kScreenWidthParameterKey);
    _screenHeight = settingsReader.getIntParameter(kScreenHeightParameterKey);

    _windowName = settingsReader.getStringParameter(kWindowNameParameterKey);
}

int Settings::getScreenWidth() const {
    return _screenWidth;
}

int Settings::getScreenHeight() const {
    return _screenHeight;
}

const std::string& Settings::getWindowName() const {
    return _windowName;
}

} //namespace Core