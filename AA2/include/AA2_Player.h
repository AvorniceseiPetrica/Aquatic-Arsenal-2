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
        AA2_Map *game_map = nullptr;

    public:

        AA2_Player(SDL_FRect *p_data, AA2_Map *p_game_map);
        ~AA2_Player();
        void Init(const char *texture_path);
        void Update();
        void Render();
        bool CheckCollision(int x, int y);
};