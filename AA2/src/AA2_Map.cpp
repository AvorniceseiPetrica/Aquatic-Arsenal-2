#include "AA2_Map.h"
#include "AA2_GameContext.h"
#include <fstream>

AA2_Map::AA2_Map()
{
    tile_manager = new AA2_TileManager();
}

AA2_Map::~AA2_Map()
{
    if(tile_manager != nullptr)
        delete tile_manager;
}

void AA2_Map::Init()
{
    tile_manager->Init();
}

void AA2_Map::LoadMap(const char* map_path)
{
    if(map_path == nullptr)
        SDL_Log("\n\tAA2_Map::LoadMap()\t<< Provided NULL for (const char *map_path) >>\n\n");
    else
    {
        std::ifstream f;

        f.open(map_path);

        if(!f.is_open())
            SDL_Log("\n\tAA2_Map::LoadMap()\t<< Could not open map file >>\n\n");
        else
        {
            for(int i = 0; i < TILEMAP_HEIGHT; i++)
                for(int j = 0; j < TILEMAP_WIDTH; j++)
                {
                    f>>tilemap[i][j];
                }
        }

        f.close();
    }
}

void AA2_Map::Render()
{
    int x, y;
    SDL_Rect camera = AA2_GameContext::GetCamera()->GetViewPort();

    for(int i = 0; i < TILEMAP_HEIGHT; i++)
        for(int j = 0; j < TILEMAP_WIDTH; j++)
        {
            x = j * TILE_WIDTH - camera.x;
            y = i * TILE_HEIGHT - camera.y;
            tile_manager->GetTile(tilemap[i][j])->Render(x, y);
        }
}

void AA2_Map::PrintMapInfo()
{
    printf("TILEMAP_WIDTH = %d | TILEMAP_HEIGHT = %d\n", TILEMAP_WIDTH, TILEMAP_HEIGHT);

    for(int i = 0; i < TILEMAP_HEIGHT; i++)
    {
        for(int j = 0; j < TILEMAP_WIDTH; j++)
            printf("%d ", tilemap[i][j]);
        
        printf("\n");
    }
}

int AA2_Map::GetTileId(int i, int j)
{
    if(i >= TILEMAP_HEIGHT || j >= TILEMAP_WIDTH)
        SDL_Log("\n\tAA2_Map::GetTileId()\t<< Invalid matrix index >>\n\n");
    
    return tilemap[i][j];
}

bool AA2_Map::IsTileSolid(int id)
{
    if(id >= TILE_COUNT)
        SDL_Log("\n\nAA2_Map::IsTileSolid()\t<< Invalid id for tile >>\n\n");
    
    return tile_manager->GetTile(id)->IsSolid();
}