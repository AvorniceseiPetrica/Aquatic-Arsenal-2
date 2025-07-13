#pragma once

#include <SDL3/SDL.h>

#include "AA2_GraphicsContext.h"

class AA2_Entity{

    protected:

        SDL_FRect *data;

        AA2_GraphicsContext *graphics_context;

    public:

        AA2_Entity(AA2_GraphicsContext *p_graphics_context, SDL_FRect *p_data);
        virtual ~AA2_Entity() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
};