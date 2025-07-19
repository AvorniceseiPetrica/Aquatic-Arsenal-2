#pragma once

#include "AA2_Creature.h"
#include "AA2_Map.h"

class AA2_Player : public AA2_Creature{

    private:

        int velocity_x;
        int velocity_y;
        int speed = 10;
        int jump_strength = 25;
        int gravity = 1;
        bool on_ground = true;
        bool moving_right = true;
        SDL_Point player_spawn;
        const char* texture_path = "Assets/Tiles/red.png";

    public:

        AA2_Player();
        ~AA2_Player();
        void Init();
        void Update() override;
        void Update(AA2_Map *p_map);
        void Render() override;
        bool CheckCollision(AA2_Map *map, int x, int y);
        SDL_Rect* GetRect();
        void ChangeSpawn(SDL_Point new_spawn);
};