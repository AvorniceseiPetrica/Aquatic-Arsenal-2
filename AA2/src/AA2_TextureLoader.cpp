#include "AA2_TextureLoader.h"

#include "AA2_RefLinks.h"

SDL_Texture* AA2_TextureLoader::LoadTexture(std::string texture_path)
{
    SDL_Surface *surface = IMG_Load(texture_path.c_str());

    if(surface == nullptr)
        SDL_Log("\n\tAA2_TileManager::LoadeTileTexture()\t<< Could not create surface from file: %s >>\n\n", texture_path.c_str());
    else
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(AA2_RefLinks::GetRenderer(), surface);

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