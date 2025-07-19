#pragma once

#include "AA2_Map.h"
#include "AA2_Player.h"
#include "AA2_Camera.h"
#include "AA2_Level.h"

class AA2_LevelManager{

    private:

        AA2_Player player;
        AA2_Level *levels[3];
        AA2_Level *current_level = nullptr;
        
    public:

        AA2_LevelManager();
        ~AA2_LevelManager();
        void Init();
        void Update();
        void Render();
        void ChangeLevel(int id);
};