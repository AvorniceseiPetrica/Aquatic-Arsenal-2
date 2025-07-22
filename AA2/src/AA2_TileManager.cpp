#include "AA2_TileManager.h"

#include "AA2_TextureLoader.h"

enum TILE_IDS{
    EMPTY = 0,
    BLACK,
    GROUND1,
    GROUND2,
    CEILING1,
    CEILING2,
    WALL1_LEFT,
    WALL1_RIGHT,
    WALL2_LEFT,
    WALL2_RIGHT,
    CORNER_LOWER_LEFT,
    CORNER_LOWER_RIGHT,
    CORNER_UPPER_LEFT,
    CORNER_UPPER_RIGHT,
    CONNECT_LOWER_LEFT,
    CONNECT_LOWER_RIGHT,
    CONNECT_UPPER_LEFT,
    CONNECT_UPPER_RIGHT
};

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
    tiles[EMPTY] = new AA2_Tile(EMPTY, false);
    LoadTileTexture(EMPTY, "Assets/Tiles/empty.png");

    tiles[BLACK] = new AA2_Tile(BLACK, true); 
    LoadTileTexture(BLACK, "Assets/Tiles/black.png");
    
    tiles[GROUND1] = new AA2_Tile(GROUND1, true);
    LoadTileTexture(GROUND1, "Assets/Tiles/ground1.png");

    tiles[GROUND2] = new AA2_Tile(GROUND2, true);
    LoadTileTexture(GROUND2, "Assets/Tiles/ground2.png");

    tiles[CEILING1] = new AA2_Tile(CEILING1, true);
    LoadTileTexture(CEILING1, "Assets/Tiles/ceiling1.png");

    tiles[CEILING2] = new AA2_Tile(CEILING2, true);
    LoadTileTexture(CEILING2, "Assets/Tiles/ceiling2.png");

    tiles[WALL1_LEFT] = new AA2_Tile(WALL1_LEFT, true);
    LoadTileTexture(WALL1_LEFT, "Assets/Tiles/wall1_left.png");

    tiles[WALL1_RIGHT] = new AA2_Tile(WALL1_RIGHT, true);
    LoadTileTexture(WALL1_RIGHT, "Assets/Tiles/wall1_right.png");

    tiles[WALL2_LEFT] = new AA2_Tile(WALL2_LEFT, true);
    LoadTileTexture(WALL2_LEFT, "Assets/Tiles/wall2_left.png");

    tiles[WALL2_RIGHT] = new AA2_Tile(WALL2_RIGHT, true);
    LoadTileTexture(WALL2_RIGHT, "Assets/Tiles/wall2_right.png");

    tiles[CORNER_LOWER_LEFT] = new AA2_Tile(CORNER_LOWER_LEFT, true);
    LoadTileTexture(CORNER_LOWER_LEFT, "Assets/Tiles/corner_lower_left.png");

    tiles[CORNER_LOWER_RIGHT] = new AA2_Tile(CORNER_LOWER_RIGHT, true);
    LoadTileTexture(CORNER_LOWER_RIGHT, "Assets/Tiles/corner_lower_right.png");

    tiles[CORNER_UPPER_LEFT] = new AA2_Tile(CORNER_UPPER_LEFT, true);
    LoadTileTexture(CORNER_UPPER_LEFT, "Assets/Tiles/corner_upper_left.png");

    tiles[CORNER_UPPER_RIGHT] = new AA2_Tile(CORNER_UPPER_RIGHT, true);
    LoadTileTexture(CORNER_UPPER_RIGHT, "Assets/Tiles/corner_upper_right.png");

    tiles[CONNECT_LOWER_LEFT] = new AA2_Tile(CONNECT_LOWER_LEFT, true);
    LoadTileTexture(CONNECT_LOWER_LEFT, "Assets/Tiles/connect_lower_left.png");

    tiles[CONNECT_LOWER_RIGHT] = new AA2_Tile(CONNECT_LOWER_RIGHT, true);
    LoadTileTexture(CONNECT_LOWER_RIGHT, "Assets/Tiles/connect_lower_right.png");

    tiles[CONNECT_UPPER_LEFT] = new AA2_Tile(CONNECT_UPPER_LEFT, true);
    LoadTileTexture(CONNECT_UPPER_LEFT, "Assets/Tiles/connect_upper_left.png");

    tiles[CONNECT_UPPER_RIGHT] = new AA2_Tile(CONNECT_UPPER_RIGHT, true);
    LoadTileTexture(CONNECT_UPPER_RIGHT, "Assets/Tiles/connect_upper_right.png");

    SDL_Log("Loaded tiles...\n");
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