#pragma once

#include "AA2_Creature.h"
#include "AA2_Map.h"

class AA2_Player : public AA2_Creature{

    private:

        int speed = 10;
        int jump_strength = 10;
        int gravity = 1;
        SDL_Rect player_rect = {
            .x = 200,
            .y = 200,
            .w = 128,
            .h = 128
        };
        const char* texture_path = "Assets/Tiles/red.png";

        AA2_Map *game_map = nullptr;

    public:

        AA2_Player(AA2_Map *p_game_map);
        ~AA2_Player();
        void Init();
        void Update();
        void Render();
        bool CheckCollision(int x, int y);
        SDL_Rect* GetRect();
};