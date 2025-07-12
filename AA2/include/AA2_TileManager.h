#pragma once

#include <SDL3_image/SDL_image.h>

#include "AA2_Tile.h"
#include "AA2_GraphicsContext.h"

class AA2_TileManager{

    private:

        AA2_Tile *tiles[TILE_COUNT];

        AA2_GraphicsContext *graphics_context = nullptr;

    public:

        AA2_TileManager(AA2_GraphicsContext *p_graphics_context);
        ~AA2_TileManager();
        void Init();
        void LoadTileTexture(int id, const char* texture_path);
        AA2_Tile* GetTile(int id);
};