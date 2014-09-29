#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

using std::string;

class Label {
private:
    string text;
    bool dirty = true;
    int x, y;
    SDL_Texture* renderedText = nullptr;
    SDL_Color textColor;

public:
    Label(int x, int y, const string& text = "");
    void setText(const string& text);
    void draw(SDL_Renderer* renderer);

    static TTF_Font* font;
};