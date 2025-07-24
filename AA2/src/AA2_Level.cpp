#include "AA2_Level.h"

#include "AA2_TextureLoader.h"
#include "AA2_RefLinks.h"
#include <fstream>

AA2_Level::AA2_Level(const char *p_map_path, const char *p_prop_map_path,const char *p_background_path, const char *p_midground_path, SDL_Point p_player_spawn)
{
    if(p_map_path == nullptr)
        SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_map_path) >>\n\n");
    else
        if(p_background_path == nullptr)
            SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_background_path) >>\n\n");
        else
            if(p_midground_path == nullptr)
                SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_midground_path) >>\n\n");
            else
                if(p_prop_map_path == nullptr)
                    SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_prop_map_path) >>\n\n");
                else
                {
                    map_path = p_map_path;
                    background_path = p_background_path;
                    midground_path = p_midground_path;
                    prop_map_path = p_prop_map_path;
                }
    
    player_spawn.x = p_player_spawn.x;
    player_spawn.y = p_player_spawn.y;
}

AA2_Level::~AA2_Level()
{

}

void AA2_Level::Init()
{
    map.Init();
    AA2_RefLinks::SetMap(&map);
    map.LoadMap(map_path);
    background = AA2_TextureLoader::LoadTexture(background_path);
    midground = AA2_TextureLoader::LoadTexture(midground_path);
    SDL_GetTextureSize(background, &background_width, &background_height);
    SDL_GetTextureSize(midground, &midground_width, &midground_height);

    LoadProps(prop_map_path);
}

void AA2_Level::Update()
{
    
}

void AA2_Level::Render()
{
    SDL_FRect background_rect = {
        .x = -(float)AA2_RefLinks::GetCamera()->GetViewPort().x * parralax_strength,
        .y = 0,
        .w = background_width,
        .h = background_height
    };

    SDL_FRect midground_rect = {
        .x = -(float)AA2_RefLinks::GetCamera()->GetViewPort().x * 0.5f,
        .y = 0,
        .w = midground_width,
        .h = midground_height
    };

    SDL_RenderTexture(AA2_RefLinks::GetRenderer(), background, nullptr, &background_rect);
    SDL_RenderTexture(AA2_RefLinks::GetRenderer(), midground, nullptr, &midground_rect);
    prop_manager.RenderProps();
    map.Render();
}


AA2_Map* AA2_Level::GetMap()
{
    return &map;
}

SDL_Point AA2_Level::GetPlayerSpawn()
{
    return player_spawn;
}

void AA2_Level::LoadProps(const char *props_config_path)
{
    if(props_config_path == nullptr) 
        SDL_Log("\n\tAA2_Level::LoadProps()\t<< Provided NULL for (const char *props_config_path) >>\n\n");
    else
    {
        std::ifstream config;

        config.open(props_config_path);

        if(!config.is_open())
            SDL_Log("\n\tAA2_Level::LoadProps()\t<< Could not open config file >>\n\n");
        else
            while(!config.eof())
            {
                char a[100];
                int x, y;

                config>>a>>x>>y;
                SDL_Log("Path: %s | x = %d | y = %d\n", a, x, y);
                prop_manager.AddProp(a, x, y);
            }
    }
}