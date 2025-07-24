#pragma once

#include "AA2_Map.h"
#include "AA2_PropManager.h"

class AA2_Level{

    private:

        AA2_Map map;
        SDL_Texture *background = nullptr;
        SDL_Texture *midground = nullptr;
        const char* map_path;
        const char* background_path;
        const char* midground_path;
        SDL_Point player_spawn;
        float background_width, background_height;
        float midground_width, midground_height;
        const float parralax_strength = 0.1;
        AA2_PropManager prop_manager;

    public:

        AA2_Level(const char *p_map_path, const char *p_background_path, const char *p_midground_path, SDL_Point p_player_spawn);
        ~AA2_Level();
        void Init();
        void Update();
        void Render();
        AA2_Map* GetMap();
        SDL_Point GetPlayerSpawn();
        void LoadProps(const char *props_config_path);
};