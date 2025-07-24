#include "AA2_Map.h"

#include <fstream>
#include "AA2_RefLinks.h"

AA2_Map::AA2_Map()
{

}

AA2_Map::~AA2_Map()
{

}

void AA2_Map::Init()
{
    tile_manager.Init();

    SDL_Log("Initialized map...\n");
}

void AA2_Map::LoadMap(std::string map_path)
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
    
    SDL_Log("Loaded map...\n");
}

void AA2_Map::Render()
{
    int x, y;
    SDL_Rect camera = AA2_RefLinks::GetCamera()->GetViewPort();
    SDL_FRect rect;

    for(int i = 0; i < TILEMAP_HEIGHT; i++)
        for(int j = 0; j < TILEMAP_WIDTH; j++)
        {
            x = j * TILE_WIDTH - camera.x;
            y = i * TILE_HEIGHT - camera.y;
            tile_manager.GetTile(tilemap[i][j])->Render(x, y);
            rect.x = x;
            rect.y = y;
            rect.w = TILE_WIDTH;
            rect.h = TILE_HEIGHT;
            // if(tile_manager.GetTile(tilemap[i][j])->IsSolid())
            //     SDL_RenderRect(AA2_RefLinks::GetRenderer(), &rect);
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
        SDL_Log("\n\tAA2_Map::GetTileId()\t<< Invalid matrix index >>\ti = %d | j = %d\n\n", i, j);
    
    return tilemap[i][j];
}

bool AA2_Map::IsTileSolid(int id)
{
    if(id >= TILE_COUNT)
        SDL_Log("\n\nAA2_Map::IsTileSolid()\t<< Invalid id for tile >>\n\n");
    
    return tile_manager.GetTile(id)->IsSolid();
}