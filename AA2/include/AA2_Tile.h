#pragma once

#include <SDL3/SDL.h>

class AA2_Tile{

    private:

        int id;
        SDL_Texture *texture = nullptr;
        bool is_solid;

    public:

        AA2_Tile(int id, bool is_solid);
        ~AA2_Tile();
        void Render();
        bool IsSolid();
};