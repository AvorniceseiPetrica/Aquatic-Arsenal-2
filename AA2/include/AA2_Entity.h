#pragma once

#include <SDL3/SDL.h>

#include "AA2_GraphicsContext.h"

class AA2_Entity{

    protected:

        SDL_Rect data;

    public:

        AA2_Entity();
        virtual ~AA2_Entity() = 0;
        virtual void Init() = 0;
        virtual void Render() = 0;
};