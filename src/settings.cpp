#include "settings.h"

#include "constants.h"

#include "scripting/settings_reader.h"

Settings::Settings()
{
    SettingsReader settingsReader;
    _screenWidth = settingsReader.getIntParameter(kScreenWidthParameterKey);
    _screenHeight = settingsReader.getIntParameter(kScreenHeightParameterKey);
}

int Settings::getScreenWidth() const {
    return _screenWidth;
}

int Settings::getScreenHeight() const {
    return _screenHeight;
}

