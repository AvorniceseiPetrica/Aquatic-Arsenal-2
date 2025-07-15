#pragma once

#include "AA2_TileManager.h"

class AA2_Map{

    private:

        int tilemap[TILEMAP_HEIGHT][TILEMAP_WIDTH];
        AA2_TileManager *tile_manager = nullptr;

    public:

        AA2_Map();
        ~AA2_Map();
        void Init();
        void LoadMap(const char* map_path);
        void Render();
        void PrintMapInfo();
        int GetTileId(int i, int j);
        bool IsTileSolid(int id);
};