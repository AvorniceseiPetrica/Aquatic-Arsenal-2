#include "AA2_Level.h"

#include "AA2_TextureLoader.h"
#include "AA2_RefLinks.h"

AA2_Level::AA2_Level(const char *p_map_path, const char *p_background_path, SDL_Point p_player_spawn)
{
    if(p_map_path == nullptr)
        SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_map_path) >>\n\n");
    else
        if(p_background_path == nullptr)
            SDL_Log("\n\tAA2_Level::AA2_Level()\t<< Provided NULL for (const char *p_background_path) >>\n\n");
        else
        {
            map_path = p_map_path;
            background_path = p_background_path;
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
    SDL_GetTextureSize(background, &background_width, &background_height);
}

void AA2_Level::Update()
{

}

void AA2_Level::Render()
{
    SDL_FRect dst = {
        .x = -(float)AA2_RefLinks::GetCamera()->GetViewPort().x * parralax_strength,
        .y = 0,
        .w = background_width,
        .h = background_height
    };
    SDL_RenderTexture(AA2_RefLinks::GetRenderer(), background, nullptr, &dst);
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