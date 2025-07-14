#include "AA2_TextureLoader.h"

SDL_Texture* AA2_TextureLoader::LoadTexture(const char *texture_path)
{
    SDL_Surface *surface = IMG_Load(texture_path);

    if(surface == nullptr)
        SDL_Log("\n\tAA2_TileManager::LoadeTileTexture()\t<< Could not create surface from file: %s >>\n\n", texture_path);
    else
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(AA2_GraphicsContext::GetRenderer(), surface);

        if(texture == nullptr)
            SDL_Log("\n\tAA2_TileManager::LoadTileTexture()\t<< Could not load texture from surface >>\n\n");
        else
        {   
            SDL_DestroySurface(surface);
            
            return texture;
        }
    }

    return nullptr;
}