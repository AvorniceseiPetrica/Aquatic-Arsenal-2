#include "AA2_TileManager.h"

AA2_TileManager::AA2_TileManager(AA2_GraphicsContext *p_graphics_context)
{
    for(int i = 0; i < TILE_COUNT; i++)
        tiles[i] = nullptr;

    for(int i = 0; i < BACKGROUND_COUNT; i++)
        backgrounds[i] = nullptr;

    if(p_graphics_context == nullptr)
        SDL_Log("\n\tAA2_TileManager::AA2_TileManager()\t<< Provided NULL for (AA2_GraphicsContext *p_graphics_context) >>\n\n");
    else
        graphics_context = p_graphics_context;

    texture_loader = new AA2_TextureLoader(graphics_context);
}

AA2_TileManager::~AA2_TileManager()
{
    for(int i = 0; i < TILE_COUNT; i++)
        delete tiles[i];
    
    if(texture_loader != nullptr)
        delete texture_loader;
}

void AA2_TileManager::Init()
{
    tiles[0] = new AA2_Tile(graphics_context, 0, false);
    LoadTileTexture(0, "Assets/Tiles/empty.png");

    tiles[1] = new AA2_Tile(graphics_context, 1, true);
    LoadTileTexture(1, "Assets/Tiles/dirt.png");
    
    tiles[2] = new AA2_Tile(graphics_context, 2, true);
    LoadTileTexture(2, "Assets/Tiles/grass.png");
}

void AA2_TileManager::LoadTileTexture(int id, const char* texture_path)
{
    SDL_Texture *tile_texture = texture_loader->LoadTexture(texture_path);
    tiles[id]->SetTexture(tile_texture);
}

AA2_Tile* AA2_TileManager::GetTile(int id)
{
    if(id >= TILE_COUNT || id < 0)
        SDL_Log("\n\tAA2_TileManager::GetTile():\t<< Invalid id provided | id = %d >>\n\n", id);
    
    return tiles[id];
}