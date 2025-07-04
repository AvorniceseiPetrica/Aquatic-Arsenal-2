#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class AA2_TextureLoader{

    public:

        SDL_Texture* loadTexture(const char *filename, SDL_Renderer *renderer);
};