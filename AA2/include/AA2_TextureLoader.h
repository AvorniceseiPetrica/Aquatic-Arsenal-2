#pragma once

#include <SDL3_image/SDL_image.h>
#include <string>

class AA2_TextureLoader{

    public:

        static SDL_Texture* LoadTexture(std::string texture_path);

};