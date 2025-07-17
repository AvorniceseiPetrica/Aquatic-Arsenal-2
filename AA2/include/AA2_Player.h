#pragma once

#include "AA2_Creature.h"
#include "AA2_Map.h"

class AA2_Player : public AA2_Creature{

    private:

        int speed = 10;
        int jump_strength = 10;
        int gravity = 1;
        int width = 128;
        int height = 128;
        SDL_Rect player_spawn = {
            .x = 200,
            .y = 200,
            .w = width,
            .h = height
        };
        const char* texture_path = "Assets/Tiles/red.png";

    public:

        AA2_Player();
        ~AA2_Player();
        void Init() override;
        void Update(AA2_Map *p_map);
        void Render() override;
        bool CheckCollision(AA2_Map *game_map, int x, int y);
        SDL_Rect* GetRect();
};