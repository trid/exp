#include <SDL.h>
#include <SDL_image.h>

class View {
public:
    static View& getView() {
        static View view;
        return view;
    };

    void draw();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* background;
    SDL_Texture* home;
    SDL_Texture* forest;
    SDL_Texture* well;

    View();
};