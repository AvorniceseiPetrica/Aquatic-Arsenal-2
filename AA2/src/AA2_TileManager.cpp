#include "AA2_TileManager.h"

AA2_TileManager::AA2_TileManager(AA2_GraphicsContext *p_graphics_context)
{
    for(int i = 0; i < TILE_COUNT; i++)
        tiles[i] = nullptr;

    if(p_graphics_context == nullptr)
        SDL_Log("\n\tAA2_TileManager::AA2_TileManager()\t<< Provided NULL for (AA2_GraphicsContext *p_graphics_context) >>\n\n");
    else
        graphics_context = p_graphics_context;
}

AA2_TileManager::~AA2_TileManager()
{
    for(int i = 0; i < TILE_COUNT; i++)
        delete tiles[i];
}

void AA2_TileManager::Init()
{
    tiles[0] = new AA2_Tile(graphics_context, 0, false);
    LoadTileTexture(0, "Assets/blue.png");

    tiles[1] = new AA2_Tile(graphics_context, 1, true);
    LoadTileTexture(1, "Assets/red.png");
    
    tiles[2] = new AA2_Tile(graphics_context, 2, true);
    LoadTileTexture(2, "Assets/yellow.png");
}

void AA2_TileManager::LoadTileTexture(int id, const char* texture_path)
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
            tiles[id]->SetTexture(texture);
        
        SDL_DestroySurface(surface);
    }
}

AA2_Tile* AA2_TileManager::GetTile(int id)
{
    if(id >= TILE_COUNT || id < 0)
        SDL_Log("\n\tAA2_TileManager::GetTile():\t<< Invalid id provided >>\n\n");
    
    return tiles[id];
}