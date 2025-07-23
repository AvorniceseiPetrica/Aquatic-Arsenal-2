#pragma once

#include "AA2_Player.h"
#include "AA2_Level.h"
#include "AA2_Config.h"

class AA2_LevelManager{

    private:

        AA2_Player player;
        AA2_Level *levels[LEVEL_COUNT];
        AA2_Level *current_level = nullptr;
        int current_level_id;
        
    public:

        AA2_LevelManager();
        ~AA2_LevelManager();
        void Init();
        void Update();
        void Render();
        void ChangeLevel(int id);
};