#include "AA2_TextureLoader.h"

AA2_TextureLoader::AA2_TextureLoader(AA2_GraphicsContext *p_graphics_context)
{
    if(p_graphics_context == nullptr)
        SDL_Log("\n\tAA2_TextureLoader::AA2_TextureLoader\t<< Provided NULL for (AA2_GraphicsContext *p_graphics_context)\n\n");
    else
        graphics_context = p_graphics_context;
}

AA2_TextureLoader::~AA2_TextureLoader()
{

}

SDL_Texture* AA2_TextureLoader::LoadTexture(const char *texture_path)
{
    SDL_Surface *surface = IMG_Load(texture_path);

    if(surface == nullptr)
        SDL_Log("\n\tAA2_TileManager::LoadeTileTexture()\t<< Could not create surface from file: %s >>\n\n", texture_path);
    else
    {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(graphics_context->renderer, surface);

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