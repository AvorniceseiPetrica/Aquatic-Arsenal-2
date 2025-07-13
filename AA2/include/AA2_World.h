#pragma once

#include "AA2_Map.h"
#include "AA2_Player.h"

class AA2_World{

    private:

        AA2_Map *map = nullptr;
        AA2_Player *player = nullptr;
        float player_spawn_x = 200;
        float player_spawn_y = 200;
        const char* player_texture_path = "Assets/Tiles/red.png";

        AA2_GraphicsContext *graphics_context = nullptr;

    public:

        AA2_World(AA2_GraphicsContext *p_graphics_context);
        ~AA2_World();
        void Init();
        void Update();
        void Render();
};