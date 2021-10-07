#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

#include "lua5.1/lua.hpp"

#include "scripting/script_context.h"
#include "scripting/settings_reader.h"

namespace Core {

class Settings {
public:
    explicit Settings();

    [[nodiscard]] int getScreenWidth() const;
    [[nodiscard]] int getScreenHeight() const;

private:
    int _screenWidth;
    int _screenHeight;
};

} // namespace Core

#endif // SETTINGS_H