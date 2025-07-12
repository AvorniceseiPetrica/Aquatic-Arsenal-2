#include "AA2_Map.h"
#include <fstream>

AA2_Map::AA2_Map(AA2_GraphicsContext *p_graphics_context)
{
    if(p_graphics_context == nullptr)
        SDL_Log("\n\tAA2_Map::AA2_Map()\t<< Provided NULL for (AA2_GraphicsContext *p_context) >>\n\n");
    else
        graphics_context = p_graphics_context;

    tile_manager = new AA2_TileManager(graphics_context);
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
            for(int i = 0; i < MAP_HEIGHT; i++)
                for(int j = 0; j < MAP_WiDTH; j++)
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

    for(int i = 0; i < MAP_HEIGHT; i++)
        for(int j = 0; j < MAP_WiDTH; j++)
        {
            x = j * TILE_WIDTH;
            y = i * TILE_HEIGHT;
            tile_manager->GetTile(tilemap[i][j])->Render(x, y);
        }
}

void AA2_Map::PrintMapInfo()
{
    printf("MAP_WIDTH = %d | MAP_HEIGHT = %d\n", MAP_WiDTH, MAP_HEIGHT);

    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 0; j < MAP_WiDTH; j++)
            printf("%d ", tilemap[i][j]);
        
        printf("\n");
    }
}