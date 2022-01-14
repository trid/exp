#ifndef SETTINGS_H
#define SETTINGS_H

#include <limits>
#include <string>

#include "../scripting/script_context.h"
#include "../scripting/settings_reader.h"

namespace Core {

class Settings {
public:
    explicit Settings();

    [[nodiscard]] int getScreenWidth() const;
    [[nodiscard]] int getScreenHeight() const;

    [[nodiscard]] const std::string& getWindowName() const;

private:
    int _screenWidth;
    int _screenHeight;

    std::string _windowName;
};

} // namespace Core

#endif // SETTINGS_H