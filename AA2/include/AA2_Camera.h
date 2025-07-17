#pragma once

#include "SDL3/SDL.h"

class AA2_Camera{

    private:

        SDL_Point position;
        SDL_Rect *target;

    public:

        AA2_Camera();
        ~AA2_Camera();
        void SetTarget(SDL_Rect *p_target);
        void Update();
        void PrintInfo();
        SDL_Rect GetViewPort();
};