#pragma once

#include <string>

#include "AA2_Map.h"
#include "AA2_PropManager.h"

class AA2_Level{

    private:

        AA2_Map map;
        SDL_Texture *background = nullptr;
        SDL_Texture *midground = nullptr;
        std::string map_path;
        std::string background_path;
        std::string midground_path;
        SDL_Point player_spawn;
        float background_width, background_height;
        float midground_width, midground_height;
        const float parralax_strength = 0.1;
        AA2_PropManager prop_manager;
        std::string prop_map_path;

    public:

        AA2_Level(std::string p_map_path, std::string p_prop_map_path, std::string p_background_path, std::string p_midground_path, SDL_Point p_player_spawn);
        ~AA2_Level();
        void Init();
        void Update();
        void Render();
        AA2_Map* GetMap();
        SDL_Point GetPlayerSpawn();
        void LoadProps(std::string props_config_path);
};