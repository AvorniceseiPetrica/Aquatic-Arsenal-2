#include "AA2_TileManager.h"

AA2_TileManager::AA2_TileManager()
{
    for(int i = 0; i < TILE_COUNT; i++)
        tiles[i] = nullptr;
}

AA2_TileManager::~AA2_TileManager()
{
    for(int i = 0; i < TILE_COUNT; i++)
        delete tiles[i];
}

void AA2_TileManager::Init()
{
    tiles[0] = new AA2_Tile(0, false);
    LoadTileTexture(0, "Assets/Tiles/empty.png");

    tiles[1] = new AA2_Tile(1, true);
    LoadTileTexture(1, "Assets/Tiles/rock.png");
    
    tiles[2] = new AA2_Tile(2, true);
    LoadTileTexture(2, "Assets/Tiles/grassy_rock.png");
}

void AA2_TileManager::LoadTileTexture(int id, const char* texture_path)
{
    SDL_Texture *tile_texture = AA2_TextureLoader::LoadTexture(texture_path);
    tiles[id]->SetTexture(tile_texture);
}

AA2_Tile* AA2_TileManager::GetTile(int id)
{
    if(id >= TILE_COUNT || id < 0)
        SDL_Log("\n\tAA2_TileManager::GetTile():\t<< Invalid id provided | id = %d >>\n\n", id);
    
    return tiles[id];
}