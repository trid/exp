#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "widget.h"

using std::string;

class UIManager;

class Label: public Widget {
public:
    Label(int x, int y, UIManager& uiManager, const string& text = "");
    void setText(const string& text);
    virtual void draw(SDL_Renderer* renderer) override;
private:
    string text;
    bool dirty = true;
    SDL_Texture* renderedText = nullptr;
    SDL_Color textColor;

    UIManager& _uiManager;
};