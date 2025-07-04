#include "AA2_TextureManager.h"
#include "AA2_Game.h"

AA2_TextureManager::AA2_TextureManager()
{
    textures = new SDL_Texture*[TXT_COUNT];
    textureLoader = new AA2_TextureLoader;
}

AA2_TextureManager::~AA2_TextureManager()
{
    if(textures != nullptr)
        delete[] textures;
    if(textureLoader != nullptr)
        delete textureLoader;
}

void AA2_TextureManager::initTextures()
{
    textures[0] = textureLoader->loadTexture("AA2/Assets/blue.png", AA2_Game::getGameRenderer());
    textures[1] = textureLoader->loadTexture("AA2/Assets/green.png", AA2_Game::getGameRenderer());
    textures[2] = textureLoader->loadTexture("AA2/Assets/red.png", AA2_Game::getGameRenderer());

    SDL_Log("Done loading textures...\n");
}

SDL_Texture* AA2_TextureManager::getTexture(int id)
{
    if(id > TXT_COUNT)
    {
        SDL_Log("\n\t<< ID for requested texture too big >>\n\n");
        
        return nullptr;
    }
    else
        return textures[id];
}