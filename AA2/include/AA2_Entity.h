#pragma once

#include <SDL3/SDL.h>

#include "AA2_GraphicsContext.h"

class AA2_Entity{

    protected:

        SDL_Rect *data = nullptr;

    public:

        AA2_Entity();
        virtual ~AA2_Entity() = 0;
        virtual void Init(SDL_Rect *p_data);
        virtual void Update() = 0;
        virtual void Render() = 0;
};