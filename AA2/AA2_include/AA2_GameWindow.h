#include "SDL.h"

class AA2_GameWindow{

    private:

        SDL_Window *wnd;
        int wnd_width;
        int wnd_height;

    public:

        AA2_GameWindow(char* title, int w, int h);

};