#pragma once

#include "AA2_Map.h"
#include "AA2_Player.h"
#include "AA2_Camera.h"

class AA2_World{

    private:

        AA2_Map *map = nullptr;
        AA2_Player *player = nullptr;
        int player_spawn_x = 200;
        int player_spawn_y = 200;
        AA2_Camera *camera = nullptr;

    public:

        AA2_World();
        ~AA2_World();
        void Init();
        void Update();
        void Render();
};