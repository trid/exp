#include <SDL.h>

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

    View();
};