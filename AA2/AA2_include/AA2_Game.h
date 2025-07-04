#pragma once    

#include <SDL3/SDL.h>

class AA2_Game{

    private:

        SDL_Window *window;
        static SDL_Renderer *gameRenderer;
        bool isRunning;

    public:

        AA2_Game();
        ~AA2_Game();
        void init(const char* title, int width, int heigth);
        void update();
        void render();
        void handleEvents();
        bool checkIfRunning();
        static SDL_Renderer* getGameRenderer();
};