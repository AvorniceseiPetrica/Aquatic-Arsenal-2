#pragma once

#include "AA2_Creature.h"

class AA2_Player : public AA2_Creature{

    private:

        int speed = 10;
        int jump_strength = 10;
        int gravity = 1;

    public:

        AA2_Player(AA2_GraphicsContext *p_graphics_context, SDL_FRect *p_data);
        ~AA2_Player();
        void Init(const char *texture_path);
        void Update();
        void Render();
};