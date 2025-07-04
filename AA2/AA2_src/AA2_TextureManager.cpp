#include "AA2_TextureManager.h"
#include "AA2_Game.h"

AA2_TextureManager::AA2_TextureManager()
{
    textures = new SDL_Texture*[TXT_COUNT];
}

AA2_TextureManager::~AA2_TextureManager()
{
    if(textures != nullptr)
        delete[] textures;
}

void AA2_TextureManager::initTextures()
{
    textures[0] = AA2_TextureLoader::loadTexture("AA2/Assets/blue.png", AA2_Game::getGameRenderer());
    textures[1] = AA2_TextureLoader::loadTexture("AA2/Assets/green.png", AA2_Game::getGameRenderer());
    textures[2] = AA2_TextureLoader::loadTexture("AA2/Assets/red.png", AA2_Game::getGameRenderer());
}

SDL_Texture* AA2_TextureManager::getTexture(int id)
{
    return textures[id];
}