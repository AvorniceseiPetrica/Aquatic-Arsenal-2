#pragma once

#include <SDL3/SDL.h>

class AA2_Game{

    private:
        
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        bool is_running = false;

    public:
        
        AA2_Game();
        ~AA2_Game();
        void Init(const char* title, int width, int height);
        void Update();
        void Render();
        bool IsRunning();
        void HandleEvents();
};