#pragma once

#include "AA2_TileManager.h"

class AA2_Map{

    private:

        int tilemap[MAP_HEIGHT][MAP_WiDTH];
        AA2_TileManager *tile_manager = nullptr;
        
        AA2_GraphicsContext *graphics_context = nullptr;

    public:

        AA2_Map(AA2_GraphicsContext *p_graphics_context);
        ~AA2_Map();
        void Init();
        void LoadMap(const char* map_path);
        void Render();
        void PrintMapInfo();
        int GetTileId(int i, int j);
        bool IsTileSolid(int id);
};