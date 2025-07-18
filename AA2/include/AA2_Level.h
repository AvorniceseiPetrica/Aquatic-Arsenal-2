#pragma once

#include "AA2_Map.h"

class AA2_Level{

    private:

        AA2_Map map;
        SDL_Texture *background = nullptr;
        const char* map_path;
        const char* background_path;

    public:

        AA2_Level(const char *p_map_path, const char *p_background_path);
        ~AA2_Level();
        void Init();
        void Update();
        void Render();
        AA2_Map* GetMap();
};