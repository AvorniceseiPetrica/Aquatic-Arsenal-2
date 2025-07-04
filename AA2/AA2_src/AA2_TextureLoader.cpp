#include "AA2_TextureLoader.h"

SDL_Texture* AA2_TextureLoader::loadTexture(const char *filename, SDL_Renderer *renderer)
{
    if(filename == nullptr)
        SDL_Log("\n\t<< NULL filename from which to load texture from >>\n\n");
    if(renderer == nullptr)
        SDL_Log("\n\t<< NULL renderer provided for loading texture >>\n\n");

    SDL_Surface *tempSurface = IMG_Load(filename);

    if(tempSurface == nullptr)
        SDL_Log("\n\t<< Could not create surface from file: %s >>\n\n", filename);
        
    SDL_Texture *txt = SDL_CreateTextureFromSurface(renderer, tempSurface);

    if(txt == nullptr)
        SDL_Log("\n\t<< Could not create texture from file: %s >>\n\n", filename);
    
    SDL_DestroySurface(tempSurface);

    return txt;
}