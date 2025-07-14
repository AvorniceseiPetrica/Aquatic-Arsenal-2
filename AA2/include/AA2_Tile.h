#pragma once

#include <SDL3/SDL.h>

#include "AA2_GraphicsContext.h"
#include "AA2_Config.h"

class AA2_Tile{

    private:

        int id;
        SDL_Texture *texture = nullptr;
        bool is_solid;

    public:

        AA2_Tile(int p_id, bool p_is_solid);
        ~AA2_Tile();
        void Render(float x, float y);
        bool IsSolid();
        void SetTexture(SDL_Texture *p_texture);
};