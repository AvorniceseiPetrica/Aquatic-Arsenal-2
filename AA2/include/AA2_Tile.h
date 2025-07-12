#pragma once

#include <SDL3/SDL.h>

#include "AA2_GraphicsContext.h"
#include "AA2_Config.h"

class AA2_Tile{

    private:

        int id;
        SDL_Texture *texture = nullptr;
        bool is_solid;

        AA2_GraphicsContext *graphics_context = nullptr;

    public:

        AA2_Tile(AA2_GraphicsContext *p_graphics_context, int p_id, bool p_is_solid);
        ~AA2_Tile();
        void Render(float x, float y);
        bool IsSolid();
        void SetTexture(SDL_Texture *p_texture);
};