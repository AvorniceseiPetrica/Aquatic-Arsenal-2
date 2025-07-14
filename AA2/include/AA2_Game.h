#pragma once

#include <SDL3/SDL.h>

#include "AA2_GraphicsContext.h"
#include "AA2_Map.h"
#include "AA2_Player.h"
#include "AA2_World.h"

class AA2_Game{

    private:
        
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        bool is_running = false;
        AA2_World *world = nullptr;

        AA2_GraphicsContext *graphics_context;

    public:
        
        AA2_Game();
        ~AA2_Game();
        void Init(const char* title);
        void Update();
        void Render();
        bool IsRunning();
        void HandleEvents();
};