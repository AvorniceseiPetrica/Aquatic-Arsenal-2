#pragma once

#include <SDL3/SDL.h>

class AA2_Entity{

    protected:

        SDL_Rect data;

    public:

        AA2_Entity();
        ~AA2_Entity();
        virtual void Update() = 0;
        virtual void Render() = 0;
};