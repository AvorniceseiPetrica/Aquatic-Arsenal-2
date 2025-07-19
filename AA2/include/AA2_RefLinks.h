#pragma once

#include <SDL3/SDL.h>
#include "AA2_Camera.h"

class AA2_RefLinks{

    private:

        static SDL_Window *window;
        static SDL_Renderer *renderer;
        static AA2_Camera *camera;

    public:

        static void Init_Graphics(SDL_Window *p_window, SDL_Renderer *p_renderer);
        static void SetCameraTarget(SDL_Rect *p_target);
        static SDL_Renderer* GetRenderer();
        static AA2_Camera* GetCamera();
};