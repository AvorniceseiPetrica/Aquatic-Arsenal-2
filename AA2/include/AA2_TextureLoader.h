#pragma once

#include <SDL3_image/SDL_image.h>

#include "AA2_GraphicsContext.h"

class AA2_TextureLoader{

    public:

        AA2_TextureLoader();
        ~AA2_TextureLoader();
        SDL_Texture* LoadTexture(const char *texture_path);

};