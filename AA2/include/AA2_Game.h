#pragma once

#include <SDL3/SDL.h>

#include "AA2_State.h"
#include "AA2_RefLinks.h"

class AA2_Game{

    private:
        
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        bool is_running = false;

        AA2_RefLinks reflinks;
        AA2_State *current_state;

    public:
        
        AA2_Game();
        ~AA2_Game();
        void Init(const char *title);
        void InitSDL(const char *title);
        void CleanSDL();
        void Update();
        void Render();
        bool IsRunning();
        void HandleEvents();
        void ChangeState(AA2_State *new_state);
};