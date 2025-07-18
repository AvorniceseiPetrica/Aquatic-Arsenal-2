#pragma once

#include "AA2_Map.h"
#include "AA2_Player.h"
#include "AA2_Camera.h"

class AA2_LevelManager{

    private:

        AA2_Map map;
        AA2_Player player;
        SDL_Texture *background = nullptr;

    public:

        AA2_LevelManager();
        ~AA2_LevelManager();
        void Init();
        void Update();
        void Render();
};