#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "widget.h"

using std::string;

class Label: public Widget {
private:
    string text;
    bool dirty = true;
    SDL_Texture* renderedText = nullptr;
    SDL_Color textColor;

public:
    Label(int x, int y, const string& text = "");
    void setText(const string& text);
    virtual void draw(SDL_Renderer* renderer) override;
};