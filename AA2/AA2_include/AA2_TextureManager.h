#pragma once

#include "AA2_TextureLoader.h"

#define TXT_COUNT 3

class AA2_TextureManager{

    private:

        SDL_Texture **textures;
        AA2_TextureLoader *textureLoader;

    public:

        AA2_TextureManager();
        ~AA2_TextureManager();
        void initTextures();
        SDL_Texture* getTexture(int id);

};