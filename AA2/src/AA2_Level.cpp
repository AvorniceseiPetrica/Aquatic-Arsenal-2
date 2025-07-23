#include "AA2_Level.h"

#include "AA2_TextureLoader.h"
#include "AA2_RefLinks.h"

AA2_Level::AA2_Level(const char *p_map_path, const char *p_background_path, const char *p_midground_path, SDL_Point p_player_spawn)
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
            {
                map_path = p_map_path;
                background_path = p_background_path;
                midground_path = p_midground_path;
            }
    
    player_spawn.x = p_player_spawn.x;
    player_spawn.y = p_player_spawn.y;
}

AA2_Level::~AA2_Level()
{

}

void AA2_Level::Init()
{
    const char *arch = "Assets/Props/arch.png";
    const char *column1 = "Assets/Props/column1.png";
    const char *column2 = "Assets/Props/column2.png";
    const char *coral1 = "Assets/Props/coral1.png";
    const char *coral2 = "Assets/Props/coral2.png";
    const char *coral3 = "Assets/Props/coral3.png";

    props[0] = new AA2_Prop(arch);
    props[1] = new AA2_Prop(column1);
    props[2] = new AA2_Prop(column2);
    props[3] = new AA2_Prop(coral1);
    props[4] = new AA2_Prop(coral2);
    props[5] = new AA2_Prop(coral3);

    
    props[0]->Init(2050, 650);

    map.Init();
    AA2_RefLinks::SetMap(&map);
    map.LoadMap(map_path);
    background = AA2_TextureLoader::LoadTexture(background_path);
    midground = AA2_TextureLoader::LoadTexture(midground_path);
    SDL_GetTextureSize(background, &background_width, &background_height);
    SDL_GetTextureSize(midground, &midground_width, &midground_height);
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
    for(auto i : props)
        i->Render();
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